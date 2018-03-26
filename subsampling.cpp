#include<subsampling.h>

std::vector<Point> Subsampling(std::vector<Point> points_on_mesh)
{
	size_t size = points_on_mesh.size();
	/*if (size == 0)
	{
		std::cout << "There is no any points on the input mesh." << std::endl;
		return -1;
	}*/

	
	points_on_mesh.erase(CGAL::hierarchy_simplify_point_set(points_on_mesh.begin(),
															points_on_mesh.end(),
														    10, // Max cluster size
														    0.1), // Max surface variation
															points_on_mesh.end());


	return points_on_mesh;
}

//std::vector<Point> GetVerticesOnMesh(OpenMesh_Mesh mesh)
//{
//	std::vector<Point> points_on_mesh;
//
//	for (OpenMesh_Mesh::VertexIter v_it = mesh.vertices_begin(); v_it != mesh.vertices_end(); ++v_it)
//	{
//		points_on_mesh.push_back(Point((mesh.point(v_it))[0], (mesh.point(v_it))[1], (mesh.point(v_it))[2]));
//
//		/*OpenMesh_Mesh::VertexHandle s = mesh.to_vertex_handle(mesh.halfedge_handle(it, 0));
//		OpenMesh_Mesh::VertexHandle t = mesh.from_vertex_handle(mesh.halfedge_handle(it, 0));
//		edges[count] = (EData *)malloc(sizeof(EData));
//		edges[count]->start = s.idx();
//		edges[count]->end = t.idx();
//		edges[count]->weight = mesh.calc_edge_sqr_length(it.handle());
//		count++;*/
//	}
//
//	return points_on_mesh;
//}
//
//std::vector<point> ChangeToBoost(std::vector<Point> points)
//{
//	std::vector<point> points_openmesh;
//	size_t size_points = points.size();
//
//	for (size_t i = 0; i < size_points; i++)
//	{
//		points_openmesh.push_back(boost::make_tuple(points[i].x(), points[i].y(), points[i].z()));
//	}
//	return points_openmesh;
//}