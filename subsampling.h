//Sinara YANG
//This functions are used for dijkstra algorithm.


#pragma once

#ifndef SUBSAMPLING_H
#define SUBSAMPLING_H



#include <iomanip>
#include <iostream>
#include <vector>

//#include <dijkstra.h>
//#include <io.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/grid_simplify_point_set.h>
#include <CGAL/IO/read_xyz_points.h>
#include <CGAL/property_map.h>
#include <CGAL/hierarchy_simplify_point_set.h>

//#include <boost/tuple/tuple.hpp>

typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;
typedef Kernel::Point_3 Point;
typedef Kernel::Vector_3 Vector;

//typedef boost::tuple<double, double, double> point;


std::vector<Point> Subsampling(std::vector<Point> points_on_mesh);

//std::vector<Point> GetVerticesOnMesh(OpenMesh_Mesh mesh);

//std::vector<point> ChangeToBoost(std::vector<Point> points);



#endif