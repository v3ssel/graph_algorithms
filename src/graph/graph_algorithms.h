#ifndef _GRAPH_ALGORITHMS_H_
#define _GRAPH_ALGORITHMS_H_

#include <vector>

#include "TSM/TravelingSalesman.h"
#include "graph.h"

namespace s21 {
    class GraphAlgorithms {
       public:
        static std::vector<int> DepthFirstSearch(const Graph& graph, int start_vertex);
        static std::vector<int> BreadthFirstSearch(const Graph& graph, int start_vertex);

        static int GetShortestPathBetweenVertices_DijkstraAlg(const Graph& graph, int vertex1, int vertex2);
        static std::vector<std::vector<int>> GetShortestPathsBetweenAllVertices_FloydWarshallAlg(const Graph &graph);
        
        static std::vector<std::vector<int>> GetLeastSpanningTree_PrimAlg(const Graph& graph);
        
        static TravelingSalesman::TsmResult SolveTravelingSalesmanProblem(const Graph &graph, TravelingSalesman* tsm_solver);

       private:
        static void CheckVertex(const Graph& graph, int vertex, const std::string& msg);
    };
} // namespace s21


#endif  // _GRAPH_ALGORITHMS_H_
