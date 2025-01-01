#include "graphvisualisation.h"
#include "ui_graphvisualisation.h"

GraphVisualisation::GraphVisualisation(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GraphVisualisation)
{
    ui->setupUi(this);
}

GraphVisualisation::~GraphVisualisation()
{
    delete ui;
}


//
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>

// Define Graph structure
class Graph {
private:
    std::map<std::string, std::vector<std::string>> adjacency_list;

public:
    void addNode(const std::string &node) {
        if (adjacency_list.find(node) == adjacency_list.end()) {
            adjacency_list[node] = {};
        }
    }

    void addEdge(const std::string &from_node, const std::string &to_node) {
        addNode(from_node);
        addNode(to_node);
        adjacency_list[from_node].push_back(to_node);
    }

    std::vector<std::string> getNeighbors(const std::string &node) const {
        auto it = adjacency_list.find(node);
        if (it != adjacency_list.end()) {
            return it->second;
        }
        return {};
    }

    std::vector<std::string> getAllNodes() const {
        std::vector<std::string> nodes;
        for (const auto &pair : adjacency_list) {
            nodes.push_back(pair.first);
        }
        return nodes;
    }
};

// Parse XML to Graph
Graph parseXMLToGraph(const std::string &input_file) {
    Graph graph;
    std::ifstream file(input_file);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << input_file << std::endl;
        return graph;
    }

    std::string line, current_user;
    while (std::getline(file, line)) {
        line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());

        if (line.find("<user>") != std::string::npos) {
            current_user.clear();
        } else if (line.find("<id>") != std::string::npos) {
            size_t start = line.find("<id>") + 4;
            size_t end = line.find("</id>");
            current_user = line.substr(start, end - start);
            graph.addNode(current_user);
        } else if (line.find("<follower>") != std::string::npos) {
            size_t start = line.find("<follower>") + 10;
            size_t end = line.find("</follower>");
            std::string follower = line.substr(start, end - start);
            graph.addEdge(follower, current_user);
        }
    }

    file.close();
    return graph;
}

// Visualize Graph using qt

class GraphVisualizer {
private:
    QGraphicsScene *scene;

public:
    GraphVisualizer() {
        scene = new QGraphicsScene();
    }

    void visualize(const Graph &graph) {
        std::map<std::string, QPointF> node_positions;
        int x = 50, y = 50;

        for (const auto &node : graph.getAllNodes()) {
            node_positions[node] = QPointF(x, y);
            x += 100;
            if (x > 500) {
                x = 50;
                y += 100;
            }

            QGraphicsEllipseItem *ellipse = scene->addEllipse(QRectF(node_positions[node], QSizeF(50, 50)), QPen(Qt::black), QBrush(Qt::lightGray));
            QGraphicsTextItem *label = scene->addText(QString::fromStdString(node));
            label->setPos(node_positions[node].x() + 10, node_positions[node].y() + 10);
        }

        for (const auto &node : graph.getAllNodes()) {
            for (const auto &neighbor : graph.getNeighbors(node)) {
                QLineF line(node_positions[node], node_positions[neighbor]);
                scene->addLine(line, QPen(Qt::blue));
            }
        }

        QGraphicsView *view = new QGraphicsView(scene);
        view->setRenderHint(QPainter::Antialiasing);
        view->resize(800, 600);
        view->show();
    }
};

// int main(int argc, char *argv[]) {
//     if (argc < 2) {
//         std::cerr << "Usage: " << argv[0] << " <input_file.xml>" << std::endl;
//         return 1;
//     }

//     std::string input_file = argv[1];
//     Graph graph = parseXMLToGraph(input_file);

//     QApplication app(argc, argv);
//     GraphVisualizer visualizer;
//     visualizer.visualize(graph);

//     return app.exec();
// }
