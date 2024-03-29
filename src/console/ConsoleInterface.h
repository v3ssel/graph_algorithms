#ifndef _CONSOLEINTERFACE_H_
#define _CONSOLEINTERFACE_H_

#include <memory>
#include "../graph/s21_graph.h"

namespace s21 {
    class ConsoleInterface {
       public:
        void run();

        virtual void helloMsg() const;
        virtual void menuMsg();
        virtual void decisionOption();
        virtual void byeMsg() const;

       protected:
        std::unique_ptr<Graph> graph_;
    
       private:
        enum class InterfaceOption {
            EXIT = -1,
            MENU,
            LOAD_GRAPH,
            EXPORT_GRAPH_DOT,
            EXPORT_GRAPH_ADJ,
            DFS,
            BFS,
            DIJKSTRA,
            FLOYD_WARSHALL,
            PRIM,
            ANT_COLONY,
            BRANCHES_AND_BOUNDS,
            GENETIC,
            TSM_RESEARCH
        } option_;
        
        void loadGraph();
        void exportGraphDot();
        void exportGraphAdj();
        void dfs();
        void bfs();
        void dijkstra();
        void floydWarshall();
        void prim();
        void antColony();
        void branchesAndBounds();
        void genetic();
        void tsmResearch();

        int readVertex();
        void printWay(const std::vector<int> &way);
        void printAdjacencyMatrix(const std::vector<std::vector<int>> &matrix);
        void wait();
    };
} // namespace s21


#endif  // _CONSOLEINTERFACE_H_
