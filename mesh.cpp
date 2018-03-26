#include <mesh.h>

int ReadSTLFile(const char *cfilename, Mesh *mesh, std::vector<Point> *points_on_mesh)
{
	int loadmask;
	MyMesh m;
	vcg::tri::io::ImporterSTL<MyMesh>::Open(m, cfilename, loadmask, 0);

	std::vector<int> index;  //index from repeated points to points without repetition
	size_t num_m_face = m.face.size() * 3;
	index.resize(num_m_face);

	//std::vector<Point> *points_on_mesh;  //delete redundant points
	(*points_on_mesh).push_back(Point(m.face[0].V(0)->P().X(), m.face[0].V(0)->P().Y(), m.face[0].V(0)->P().Z()));
	for (int i = 1; i < num_m_face; i++)
	{
		size_t number_vertex_face = (*points_on_mesh).size();
		int flag = -1;
		for (int j = 0; j < number_vertex_face; j++)
		{
			if ((m.face[i / 3].V(i % 3)->P().X() == (*points_on_mesh)[j].x())
				&& (m.face[i / 3].V(i % 3)->P().Y() == (*points_on_mesh)[j].y())
				&& (m.face[i / 3].V(i % 3)->P().Z() == (*points_on_mesh)[j].z()))
			{
				index[i] = j;
				flag = j;
				break;
			}
		}
		if (-1 != flag)
		{
			continue;
		}
		index[i] = number_vertex_face;
		(*points_on_mesh).push_back(K::Point_3(m.face[i / 3].V(i % 3)->P().X(),
			m.face[i / 3].V(i % 3)->P().Y(),
			m.face[i / 3].V(i % 3)->P().Z()));
	}

	std::vector<vertex_descriptor> vertex_on_mesh;  //for add_face in mesh
	size_t number_vertex = (*points_on_mesh).size();
	for (int i = 0; i < number_vertex; i++)
	{
		vertex_on_mesh.push_back((*mesh).add_vertex(K::Point_3((*points_on_mesh)[i].x(), (*points_on_mesh)[i].y(), (*points_on_mesh)[i].z())));
	}

	for (int i = 0; i < num_m_face; i = i + 3)
	{
		(*mesh).add_face(vertex_on_mesh[index[i]], vertex_on_mesh[index[i + 1]], vertex_on_mesh[index[i + 2]]);
	}
	return 0;
}

int OutputAsTXT1(std::vector<Point> points_on_mesh)
{
	std::ofstream outdata;
	std::string name_file = "C:\\Users\\sinara\\Desktop\\points_on_mesh.txt";
	outdata.open(name_file, ios::out);
	outdata.clear();

	const size_t size_points_on_mesh = points_on_mesh.size();
	for (std::size_t i = 0; i < size_points_on_mesh; ++i)
	{
		outdata << std::fixed << std::setprecision(8) << points_on_mesh[i].x() << " "
			<< std::fixed << std::setprecision(8) << points_on_mesh[i].y() << " "
			<< std::fixed << std::setprecision(8) << points_on_mesh[i].z() << std::endl;
		//outdata << points_on_mesh[i].x() << " " << points_on_mesh[i].y() << " " << points_on_mesh[i].z() << std::endl;
	}
	return 0;
}

int OutputAsTXT2(std::vector<Point> subsampled_points)
{
	std::ofstream outdata;
	std::string name_file = "C:\\Users\\sinara\\Desktop\\subsampled_points.txt";
	outdata.open(name_file, ios::out);
	outdata.clear();

	const size_t size_points_on_mesh = subsampled_points.size();
	for (std::size_t i = 0; i < size_points_on_mesh; ++i)
	{
		outdata << std::fixed << std::setprecision(8) << subsampled_points[i].x() << " " 
			    << std::fixed << std::setprecision(8) << subsampled_points[i].y() << " " 
			    << std::fixed << std::setprecision(8) << subsampled_points[i].z() << std::endl;
	}
	return 0;
}


