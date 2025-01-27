#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>
#include <cstdlib>
int l;
struct edge{
    int x,y,z;
};
std::vector<edge> v;
void create_edge(int pos, int left)
{
    if(pos == 20) return;
    if(left == 0)
    {
        v.push_back({pos, pos+1, 0});
        create_edge(pos+1, left);
    }
    else if(left % 2)
    {
        v.push_back({pos, pos+1, 0});
        v.push_back({pos, pos+1, left/2+1});
        create_edge(pos+1, left/2);
    }
    else
    {
        v.push_back({pos, pos+1, 0});
        v.push_back({pos, pos+1, left/2});
        v.push_back({pos, 20, left});
        create_edge(pos+1, left/2-1);
    }
}
int main()
{
    scanf("%d", &l);
    create_edge(1, l-1);
    printf("20 %d\n", v.size());
    for(edge& e : v)
    {
        printf("%d %d %d\n", e.x, e.y, e.z);
    }
}