#include <limits>
#include <chrono>
#include <iostream>
#include <iomanip>
#include <future>

#include "../graph/graph_algorithms.h"
#include "ConsoleInterface.h"

#include "../graph/TSM/AntColonyTSM.h"
#include "../graph/TSM/GeneticTSM.h"
#include "../graph/TSM/BranchesAndBoundsTSM.h"

namespace s21 {
    void ConsoleInterface::run() {
        helloMsg();
        option_ = InterfaceOption::MENU;
        while (option_ != InterfaceOption::EXIT) {
            if (graph_ == nullptr) {
                loadGraph();
                continue;
            }
            menuMsg();
            decisionOption();
        }
        byeMsg();
    }
    
    void ConsoleInterface::helloMsg() const {
        system("clear");
        std::cout << "Hello, this is a console interface of SimpleNavigator." << std::endl;
        std::cout << "The project about few graph algorithms." << std::endl;
        std::cout << "To use this program load graph from adjacency matrix and enter any number from menu." << std::endl;
        std::cout << "To exit enter -1." << std::endl;
    }

    void ConsoleInterface::menuMsg() {
        system("clear");
        std::cout << "[MENU]" << std::endl;
        std::cout << "\nAvailable options:" << std::endl;
        std::cout << static_cast<int>(InterfaceOption::LOAD_GRAPH)          << ". Load other graph." << std::endl;
        std::cout << static_cast<int>(InterfaceOption::EXPORT_GRAPH_DOT)    << ". Export the graph to the DOT format." << std::endl;
        std::cout << static_cast<int>(InterfaceOption::EXPORT_GRAPH_ADJ)    << ". Export the graph as adjacency matrix." << std::endl;
        std::cout << static_cast<int>(InterfaceOption::DFS)                 << ". Depth First Search way of graph." << std::endl;
        std::cout << static_cast<int>(InterfaceOption::BFS)                 << ". Breadth First Search way of graph." << std::endl;
        std::cout << static_cast<int>(InterfaceOption::DIJKSTRA)            << ". Dijkstra's algorithm for finding shortest path." << std::endl;
        std::cout << static_cast<int>(InterfaceOption::FLOYD_WARSHALL)      << ". Floyd-Warshall algorithm for finding shortest paths between all combinations." << std::endl;
        std::cout << static_cast<int>(InterfaceOption::PRIM)                << ". Prim's algorithm for finding least spanning tree of graph." << std::endl;
        std::cout << static_cast<int>(InterfaceOption::ANT_COLONY)          << ". Ant-Colony algorithm for solving the Traveling Salesman Problem." << std::endl;
        std::cout << static_cast<int>(InterfaceOption::BRANCHES_AND_BOUNDS) << ". Branches And Bounds algorithm for solving the Traveling Salesman Problem." << std::endl;
        std::cout << static_cast<int>(InterfaceOption::GENETIC)             << ". Genetic algorithm for solving the Traveling Salesman Problem." << std::endl;
        std::cout << static_cast<int>(InterfaceOption::TSM_RESEARCH)        << ". Research between Traveling Salesman Problem solving algorithms." << std::endl;

        std::cout << static_cast<int>(InterfaceOption::EXIT) << ". Exit." << std::endl;

        std::cout << "Please select an option." << std::endl;
        while ((option_ < InterfaceOption::LOAD_GRAPH || option_ > InterfaceOption::TSM_RESEARCH) && option_ != InterfaceOption::EXIT) {
            int tmp_opt;
            std::cin >> tmp_opt;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid option, please enter correct value." << std::endl;
                continue;
            }

            option_ = static_cast<InterfaceOption>(tmp_opt);
        }
    }

    void ConsoleInterface::decisionOption() {
        switch (option_) {
            case InterfaceOption::EXIT:
                return;

            case InterfaceOption::MENU:
                return;

            case InterfaceOption::LOAD_GRAPH:
                system("clear");
                loadGraph();
                break;

            case InterfaceOption::EXPORT_GRAPH_DOT:
                system("clear");
                exportGraphDot();
                break;

            case InterfaceOption::EXPORT_GRAPH_ADJ:
                system("clear");
                exportGraphAdj();
                break;

            case InterfaceOption::DFS:
                system("clear");
                dfs();
                break;
                
            case InterfaceOption::BFS:
                system("clear");
                bfs();
                break;
                
            case InterfaceOption::DIJKSTRA:
                system("clear");
                dijkstra();
                break;
                
            case InterfaceOption::FLOYD_WARSHALL:
                system("clear");
                floydWarshall();
                break;
                
            case InterfaceOption::PRIM:
                system("clear");
                prim();
                break;
                
            case InterfaceOption::ANT_COLONY:
                system("clear");
                antColony();
                break;
                
            case InterfaceOption::BRANCHES_AND_BOUNDS:
                system("clear");
                branchesAndBounds();
                break;
                
            case InterfaceOption::GENETIC:
                system("clear");
                genetic();
                break;
                
            case InterfaceOption::TSM_RESEARCH:
                system("clear");
                tsmResearch();
                break;
        }
        option_ = InterfaceOption::MENU;
    }

    void ConsoleInterface::byeMsg() const {
        std::cout << "Goodbye!" << std::endl;
    }

    void ConsoleInterface::loadGraph() {
        std::cout << "\n[LOADING GRAPH]" << std::endl;
        std::cout << "You need to load a graph from adjacency matrix." << std::endl;
        std::cout << "Please enter a path to file." << std::endl;

        std::string path;
        std::cin >> path;

        while (path != std::to_string(static_cast<int>(InterfaceOption::EXIT))) {
            try {
                auto g = std::make_unique<Graph>();
                g->LoadGraphFromFile(path);
                system("clear");
                std::cout << "[SUCCESS] Graph loaded successfully." << std::endl;

                graph_ = std::move(g);
                wait();
                
                return;
            } catch (std::exception &e) {
                std::cout << "[FAIL] An error occured: " << e.what() << std::endl;
                std::cout << "[FAIL] Please try again or enter -1 to exit." << std::endl;
                std::cin >> path;
            }
        }

        std::cout << "You denied operation of loading graph." << std::endl;

        if (graph_ == nullptr)
            std::cout << "If not any graph loaded, you will be returned until any valid graph is loaded." << std::endl;

        wait();
    }

    void ConsoleInterface::exportGraphDot() {
        system("clear");
        std::cout << "\n[EXPORTING GRAPH IN DOT FORMAT]" << std::endl;
        std::cout << "Please enter a path to file." << std::endl;

        std::string path;
        std::cin >> path;

        try {
            graph_->ExportGraphToDot(path);
            std::cout << "[SUCCESS] Graph exported successfully." << std::endl;

        } catch (std::exception &e) {
            std::cout << "[FAIL] An error occured: " << e.what() << std::endl;
            std::cout << "[FAIL] Graph has not been exported." << std::endl;
        }
        wait();
    }

    void ConsoleInterface::exportGraphAdj() {
        system("clear");
        std::cout << "\n[EXPORTING GRAPH AS ADJACENCY MATRIX]" << std::endl;
        std::cout << "Please enter a path to file." << std::endl;

        std::string path;
        std::cin >> path;

        try {
            graph_->ExportGraphAdjMatrix(path);
            std::cout << "[SUCCESS] Graph exported successfully." << std::endl;

        } catch (std::exception &e) {
            std::cout << "[FAIL] An error occured: " << e.what() << std::endl;
            std::cout << "[FAIL] Graph has not been exported." << std::endl;
        }
        wait();
    }

    void ConsoleInterface::dfs() {
        std::cout << "\n[DEPTH FIRST SEARCH]" << std::endl;

        std::cout << "[START VERTEX] ";
        int start_vertex = readVertex();
        if (start_vertex == -1) return;

        try {
            auto way = s21::GraphAlgorithms::DepthFirstSearch(*graph_, start_vertex);
            std::cout << "[SUCCESS] Depth first search completed successfully." << std::endl;
            std::cout << "Way of depth first search:" << std::endl;
            printWay(way);

        } catch (std::exception &e) {
            std::cout << "[FAIL] An error occured: " << e.what() << std::endl;
            std::cout << "[FAIL] Operation denied." << std::endl;
        }
        wait();
    }

    void ConsoleInterface::bfs() {
        std::cout << "\n[BREADTH FIRST SEARCH]" << std::endl;
        
        std::cout << "[START VERTEX] ";
        int start_vertex = readVertex();
        if (start_vertex == -1) return;

        try {
            auto way = s21::GraphAlgorithms::BreadthFirstSearch(*graph_, start_vertex);
            std::cout << "[SUCCESS] Breadth first search completed successfully." << std::endl;
            std::cout << "Way of breadth first search:" << std::endl;
            printWay(way);

        } catch (std::exception &e) {
            std::cout << "[FAIL] An error occured: " << e.what() << std::endl;
            std::cout << "[FAIL] Operation denied." << std::endl;
        }
        wait();
    }

    void ConsoleInterface::dijkstra() {
        std::cout << "\n[DIJKSTRA'S ALGORITHM FOR FINDING SHORTEST PATH]" << std::endl;

        std::cout << "[START VERTEX] ";
        int start_vertex = readVertex();
        if (start_vertex == -1) return;

        std::cout << "[END VERTEX] ";
        int end_vertex = readVertex();
        if (end_vertex == -1) return;

        try {
            int cost = s21::GraphAlgorithms::GetShortestPathBetweenVertices_DijkstraAlg(*graph_, start_vertex, end_vertex);
            std::cout << "[SUCCESS] Finding shortest path between vertices " << start_vertex << " and " << end_vertex << " completed successfully." << std::endl;
            std::cout << "Shortest way will cost: " << cost << std::endl;

        } catch (std::exception &e) {
            std::cout << "[FAIL] An error occured: " << e.what() << std::endl;
            std::cout << "[FAIL] Operation denied." << std::endl;
        }
        wait();
    }

    void ConsoleInterface::floydWarshall() {
        std::cout << "\n[FLOYD-WARSHALL ALGORITHM]" << std::endl;
        std::cout << "[FOR FINDING SHORTEST PATH BETWEEN ALL VERTICES COMBINATIONS]" << std::endl;

        try {
            auto costs = s21::GraphAlgorithms::GetShortestPathsBetweenAllVertices_FloydWarshallAlg(*graph_);
            std::cout << "[SUCCESS] Finding shortest path between all vertices completed successfully." << std::endl;
            std::cout << "Adjacency matrix of shortest ways: " << std::endl;
            printAdjacencyMatrix(costs);

        } catch (std::exception &e) {
            std::cout << "[FAIL] An error occured: " << e.what() << std::endl;
            std::cout << "[FAIL] Operation denied." << std::endl;
        }
        wait();
    }

    void ConsoleInterface::prim() {
        std::cout << "\n[PRIM'S ALGORITHM]" << std::endl;
        std::cout << "[FOR FINDING MINIMAL SPANNING TREE IN THE GRAPH]" << std::endl;

        try {
            auto costs = s21::GraphAlgorithms::GetLeastSpanningTree_PrimAlg(*graph_);
            std::cout << "[SUCCESS] Finding minimal spanning tree completed successfully." << std::endl;
            std::cout << "Adjacency matrix of spanning tree: " << std::endl;
            printAdjacencyMatrix(costs);

        } catch (std::exception &e) {
            std::cout << "[FAIL] An error occured: " << e.what() << std::endl;
            std::cout << "[FAIL] Operation denied." << std::endl;
        }
        wait();
    }

    void ConsoleInterface::antColony() {
        std::cout << "\n[ANT COLONY ALGORITHM]" << std::endl;
        std::cout << "[FOR SOLVING TRAVELING SALESMAN PROBLEM]" << std::endl;

        try {
            AntColonyTSM tsm;
            auto tsm_result = s21::GraphAlgorithms::SolveTravelingSalesmanProblem(*graph_, &tsm);

            std::cout << "[SUCCESS] Solving TSM completed successfully." << std::endl;
            std::cout << "Total TSM distance: " << tsm_result.distance << "." << std::endl;
            std::cout << "Way of TSM: " << std::endl;
            printWay(tsm_result.vertices);

        } catch (std::exception &e) {
            std::cout << "[FAIL] An error occured: " << e.what() << std::endl;
            std::cout << "[FAIL] Operation denied." << std::endl;
        }
        wait();
    }

    void ConsoleInterface::branchesAndBounds() {
        std::cout << "\n[BRANCHES AND BOUNDS ALGORITHM]" << std::endl;
        std::cout << "[FOR SOLVING TRAVELING SALESMAN PROBLEM]" << std::endl;

        try {
            BranchesAndBoundsTSM tsm;
            auto tsm_result = s21::GraphAlgorithms::SolveTravelingSalesmanProblem(*graph_, &tsm);
            
            std::cout << "[SUCCESS] Solving TSM completed successfully." << std::endl;
            std::cout << "Total TSM distance: " << tsm_result.distance << "." << std::endl;
            std::cout << "Way of TSM: " << std::endl;
            printWay(tsm_result.vertices);

        } catch (std::exception &e) {
            std::cout << "[FAIL] An error occured: " << e.what() << std::endl;
            std::cout << "[FAIL] Operation denied." << std::endl;
        }
        wait();
    }

    void ConsoleInterface::genetic() {
        std::cout << "\n[GENETIC ALGORITHM]" << std::endl;
        std::cout << "[FOR SOLVING TRAVELING SALESMAN PROBLEM]" << std::endl;

        try {
            GeneticTSM tsm;
            auto tsm_result = s21::GraphAlgorithms::SolveTravelingSalesmanProblem(*graph_, &tsm);
            
            std::cout << "[SUCCESS] Solving TSM completed successfully." << std::endl;
            std::cout << "Total TSM distance: " << tsm_result.distance << "." << std::endl;
            std::cout << "Way of TSM: " << std::endl;
            printWay(tsm_result.vertices);

        } catch (std::exception &e) {
            std::cout << "[FAIL] An error occured: " << e.what() << std::endl;
            std::cout << "[FAIL] Operation denied." << std::endl;
        }
        wait();
    }

    void ConsoleInterface::tsmResearch() {
        std::cout << "\n[RESEARCH BETWEEN TRAVELING SALESMAN PROBLEM ALGORITHMS]" << std::endl;
        std::cout << "[THERE ARE THREE DIFFERENT ALGORITHMS FOR SOLVING TRAVELING SALESMAN PROBLEM]" << std::endl;
        std::cout << "[ANT COLONY, GENETIC ALGORITHM AND BRANCHES AND BOUNDS]" << std::endl;
        std::cout << "[THE PURPOSE OF RESEARCH IS TO COMPARE THE SPEED OF EXECUTION OF THESE ALGORITHMS]" << std::endl;
        std::cout << "[PLEASE, ENTER THE NUMBER OF ITERATIONS]" << std::endl;

        try {
            size_t N;
            while (true) {
                std::cin >> N;
                
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "[FAIL] Invalid input. Try again" << std::endl;

                    continue;
                }

                break;
            }

            auto ants_ft = std::async([N, this]() {
                auto start = std::chrono::high_resolution_clock().now().time_since_epoch();
                for (size_t i = 0; i < N; i++) {
                    AntColonyTSM tsm;
                    auto tsm_result = s21::GraphAlgorithms::SolveTravelingSalesmanProblem(*graph_, &tsm);
                }
                auto end = std::chrono::high_resolution_clock().now().time_since_epoch();

                return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() / 1000.0;
            });

            auto genetic_ft = std::async([N, this]() {
                auto start = std::chrono::high_resolution_clock().now().time_since_epoch();
                for (size_t i = 0; i < N; i++) {
                    GeneticTSM tsm;
                    auto tsm_result = s21::GraphAlgorithms::SolveTravelingSalesmanProblem(*graph_, &tsm);
                }
                auto end = std::chrono::high_resolution_clock().now().time_since_epoch();

                return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() / 1000.0;
            });

            auto bnb_ft = std::async([N, this]() {
                auto start = std::chrono::high_resolution_clock().now().time_since_epoch();
                for (size_t i = 0; i < N; i++) {
                    BranchesAndBoundsTSM tsm;
                    auto tsm_result = s21::GraphAlgorithms::SolveTravelingSalesmanProblem(*graph_, &tsm);
                }
                auto end = std::chrono::high_resolution_clock().now().time_since_epoch();

                return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() / 1000.0;
            });

            std::cout << "Total time taken by ant colony algorithm: "
                      << ants_ft.get() << " seconds." << std::endl;

            std::cout << "Total time taken by genetic algorithm: "
                      << genetic_ft.get() << " seconds." << std::endl;
  
            std::cout << "Total time taken by branches and bounds algorithm: "
                      << bnb_ft.get() << " seconds." << std::endl;

        } catch (std::exception &e) {
            std::cout << "[FAIL] An error occured: " << e.what() << std::endl;
            std::cout << "[FAIL] Operation denied." << std::endl;
        }
        wait();
    }

    int ConsoleInterface::readVertex() {
        std::cout << "Please enter a vertex." << std::endl;

        int start_vertex;
        std::cin >> start_vertex;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "[FAIL] Invalid vertex value, operation denied." << std::endl;

            return -1;
        }

        return start_vertex;
    }
    
    void ConsoleInterface::printWay(const std::vector<int> &way) {
        for (size_t i = 0; i < way.size() - 1; i++) {
            std::cout << way[i] << " -> ";
        }

        std::cout << way.back() << std::endl;
    }

    void ConsoleInterface::printAdjacencyMatrix(const std::vector<std::vector<int>> &matrix) {
        int width = std::to_string(matrix.size()).length() + 1;
        std::cout << std::setw(width + 1) << "|";

        for (size_t i = 0; i < matrix.size(); i++) {
            std::cout << std::setw(width) << i + 1 << "|";
        }
        std::cout << std::endl;
        
        std::cout.fill('-');
        for (size_t i = 0; i < matrix.size() + 1; i++) {
            std::cout << std::setw(width + 1) << "|";
        }
        std::cout << std::endl;
        std::cout.fill(' ');

        for (size_t i = 0; i < matrix.size(); i++) {
            std::cout << std::setw(width) << i + 1 << "|";
            for (size_t j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] > 0) {
                    std::cout << std::setw(width) << matrix[i][j] << "|";
                } else {
                    std::cout << std::setw(width) << "." << "|";
                }
            }
            std::cout << std::endl;
        }
    }

    void ConsoleInterface::wait() {
        std::cout << "\nPress enter to continue..." << std::endl;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::string line;
        std::getline(std::cin, line);
    }
}
