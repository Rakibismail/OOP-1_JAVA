#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <queue>

using namespace std;

enum Color {White = 1, Gray, Black};

struct node
{
    int vertex;
    Color curr_color;
    int discovery_time;
    list<int> *adj = new list<int>;
};

vector<node> Node_list;

void makeAdjacency(int num_of_vertex)
{
    cout<< "Enter Adjacency Lists\n";
    cout<< "****** Enter a '-1' to end the list of a node *******"<< endl;
    for(int i=0;i<num_of_vertex;i++)
    {
        cout<< "Vertex " << i << endl;
        int adjacent;
        while(1)
        {
            cin>> adjacent;
            if(adjacent == -1)
                break;
            Node_list[i].adj->push_back(adjacent);
        }
        cout<< endl;
    }
}

void printAdjacency(int num_of_vertex)
{
    cout<< " -------------------- Adjacency List --------------------"<<endl;
    cout<< "Vertex adjacent"<<endl;
    for(int i=0;i<num_of_vertex;i++)
    {
        cout<< i << "\t [";
        for(list<int>::iterator it = Node_list[i].adj->begin(); it != Node_list[i].adj->end(); it++)
        {
            cout<< *it << ",";
        }
        cout<< "]" << endl;
    }
}

void BFS(int startNode)
{
    queue<node> Q;

    Q.push(Node_list[startNode]);
    node currentNode;

    while(!Q.empty())
    {
        currentNode = Q.front();
        for(list<int>::iterator it=currentNode.adj->begin(); it != currentNode.adj->end(); it++)
        {
            if(Node_list[*it].curr_color == White)
            {
                Node_list[*it].curr_color = Gray;
                Node_list[*it].discovery_time = currentNode.discovery_time + 1;
                Q.push(Node_list[*it]);
            }
        }

        cout<< "Current Node: "<< currentNode.vertex << endl;
        cout<< "Discovery Time: "<< currentNode.discovery_time << endl;
        currentNode.curr_color = Black;
        Q.pop();
    }
}

int main()
{
    int num_of_vertex;
    int i;
    cout<< "Enter number of vertex: ";
    cin>> num_of_vertex;

    for(i=0;i<num_of_vertex;i++)
    {
        node tmp;
        tmp.vertex = i;
        tmp.curr_color = White;
        tmp.discovery_time = 0;
        Node_list.push_back(tmp);
    }
    makeAdjacency(num_of_vertex);
    printAdjacency(num_of_vertex);

    cout<< "Enter the starting node for BFS visit"<<endl;
    int startNode;
    cin>> startNode;
    BFS(startNode);
    return 0;
}
