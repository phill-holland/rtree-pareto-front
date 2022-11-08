#include <iostream>
#include <boost/geometry.hpp>
#include <boost/geometry/index/rtree.hpp>
#include <boost/geometry/geometries/adapted/std_array.hpp>
#include <vector>

namespace bg = boost::geometry;
namespace bgi = boost::geometry::index;

BOOST_GEOMETRY_REGISTER_STD_ARRAY_CS(bg::cs::cartesian)

typedef std::array<int, 2> point;
typedef bg::model::box<point> box;

int main(int argc, char *argv[])
{
    int points[][2] = { {97,23},{55,77},{34,76},{80,60},{99,04},{81,05},{05,81},{30,79},{15,80},{70,65},
                    {90,40},{40,30},{30,40},{20,60},{60,50},{20,20},{30,01},{60,40},{70,25},{44,62},
                    {55,55},{55,10},{15,45},{83,22},{76,46},{56,32},{45,55},{10,70},{10,30},{79,50}
                };

    const int count = 30;

    bgi::rtree<point,bgi::linear<count,4>> rtree;
    
    bool is_front[count];

	for(int i = 0; i < count; ++i)
	{	
        is_front[i] = true;

        point a;

        bg::set<0>(a, points[i][0]);
        bg::set<1>(a, points[i][1]);

        rtree.insert(a);
	}

    for(int i = 0; i < count; ++i)
	{
        point a;

        bg::set<0>(a, points[i][0]);
        bg::set<1>(a, points[i][1]);

		for(int j = 0; j < count; ++j)
		{
			if(i != j)
			{
                point b;

                bg::set<0>(b, points[j][0]);
                bg::set<1>(b, points[j][1]);

                point origin;

                bg::set<0>(origin,0);
                bg::set<1>(origin,1);

                box query_box(origin,b);
                std::vector<point> results;

                rtree.query(bgi::intersects(query_box),std::back_inserter(results));

                for(point res : results)
                {
                    int x1 = res[0];
                    int y1 = res[1];

                    int x2 = a[0];
                    int y2 = a[1];

                    if((x1==x2)&&(y1==y2))
                    {
                        is_front[i] = false;
                    }
                }
			}
		}
	}

    std::cout << "Pareto Front;\n";

	for(int i = 0; i < count; ++i)
	{
		if(is_front[i]) 
		{
            std::cout << points[i][0] << "," << points[i][1] << "\r\n";
		}
	}

    return 0;
}