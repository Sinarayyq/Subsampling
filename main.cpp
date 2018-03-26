//#include <dijkstra.h>
#include <mesh.h>
#include <subsampling.h>
#include <time.h>



int main()
{
	time_t start = clock();

	std::string load_file;
	std::getline(std::cin, load_file);
	Mesh mesh;
	std::vector<Point> points_on_mesh;
	ReadSTLFile(load_file.c_str(), &mesh, &points_on_mesh);
	/*OpenMesh_Mesh mesh;
	if (!OpenMesh::IO::read_mesh(mesh, "some input file"))
	{
		std::cerr << "read error\n";
		exit(1);
	}*/
	//std::cout <<mesh.edges().size();

	//std::vector<Point> points_on_mesh = GetVerticesOnMesh(mesh);

	std::vector<Point> subsampled_points = Subsampling(points_on_mesh);

	size_t size_points_on_mesh = points_on_mesh.size();
	int no_start_point = 0;
	for (size_t i = 0; i < size_points_on_mesh; i++)
	{
		
		if (subsampled_points[10] == points_on_mesh[i])
		{
			std::cout << subsampled_points[10] << std::endl;
			std::cout << no_start_point << std::endl;
			break;
		}
		no_start_point++;
	}

	//std::vector<point> subsampled_points_boost = ChangeToBoost(subsampled_points);

	OutputAsTXT1(points_on_mesh);
	OutputAsTXT2(subsampled_points);

	//OpenMesh_Mesh::Point start_point(OpenMesh_Mesh::Point(subsampled_points[10].x(), subsampled_points[10].y(), subsampled_points[10].z()));

	//The first list is the distance and the second is the No. of subsampled points 
	std::vector<std::vector<double>> distance; 
	//DijkstraAlgorithm(mesh, subsampled_points_boost, start_point, &distance);
	//Floyd(mesh, subsampled_points);
	//mesh.edges().size();

	

	//Visualizer(points_on_mesh, subsampled_points, distance);

	return 0;
}