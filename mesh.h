//Sinara YANG
//This functions are used to generate good-quality mesh.


#pragma once

#ifndef MESH_H
#define MESH_H



#include <iostream>
#include <fstream>
#include <vector>


#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Surface_mesh.h>
#include <CGAL/boost/graph/graph_traits_Surface_mesh.h>
#include <CGAL/Polygon_mesh_processing/remesh.h>
#include <CGAL/Polygon_mesh_processing/border.h>
#include <CGAL/Polygon_mesh_processing/compute_normal.h>
#include <CGAL/Simple_cartesian.h>
#include <CGAL/wlop_simplify_and_regularize_point_set.h>
#include <CGAL/IO/read_xyz_points.h>
#include <CGAL/IO/write_xyz_points.h>
#include <CGAL/grid_simplify_point_set.h>
#include <boost/function_output_iterator.hpp>
#include <wrap/io_trimesh/import.h>
#include <wrap/io_trimesh/export.h>
#include <wrap/ply/plylib.h>



//#include <dijkstra.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_3 Point;
typedef CGAL::Surface_mesh<K::Point_3> Mesh;
//typedef Mesh::Vertex_index vertex_descriptor;
typedef Mesh::Edge_index edge_index;
typedef Mesh::Edge_iterator edge_iterator;
typedef Mesh::Vertex_iterator vertex_iterator;
typedef K::Vector_3 Vector;

typedef boost::graph_traits<Mesh>::halfedge_descriptor halfedge_descriptor;
typedef boost::graph_traits<Mesh>::edge_descriptor     edge_descriptor;

typedef boost::graph_traits<Mesh>::vertex_descriptor vertex_descriptor;
typedef boost::graph_traits<Mesh>::face_descriptor   face_descriptor;



typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_3 Point;
typedef CGAL::Surface_mesh<K::Point_3> Mesh;

class MyVertex;
class MyEdge;
class MyFace;

struct MyUsedTypes : public vcg::UsedTypes<vcg::Use<MyVertex> ::AsVertexType,
	vcg::Use<MyEdge> ::AsEdgeType,
	vcg::Use<MyFace> ::AsFaceType> {};
class MyVertex : public vcg::Vertex< MyUsedTypes, vcg::vertex::Coord3f, vcg::vertex::Normal3f, vcg::vertex::BitFlags > {};
class MyFace : public vcg::Face< MyUsedTypes, vcg::face::FFAdj, vcg::face::VertexRef, vcg::face::BitFlags > {};
class MyEdge : public vcg::Edge< MyUsedTypes> {};
class MyMesh : public vcg::tri::TriMesh< std::vector<MyVertex>, std::vector<MyFace>, std::vector<MyEdge> > {};




//
//struct halfedge2edge
//{
//	halfedge2edge(const Mesh& m, std::vector<edge_descriptor>& edges)
//		: m_mesh(m), m_edges(edges)
//	{}
//	void operator()(const halfedge_descriptor& h) const
//	{
//		m_edges.push_back(edge(h, m_mesh));
//	}
//	const Mesh& m_mesh;
//	std::vector<edge_descriptor>& m_edges;
//};




int ReadSTLFile(const char *cfilename, Mesh *mesh, std::vector<Point> *points_on_mesh);

int OutputAsTXT1(std::vector<Point> points_on_mesh);

int OutputAsTXT2(std::vector<Point> subsampled_points);




#endif