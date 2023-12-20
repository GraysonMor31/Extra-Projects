package Algorithms.Graphs;

import java.util.*;

public class ShortestPath<T> {
    private Map<Integer, List<Integer>> adjVertices;

    public ShortestPath() {
        this.adjVertices = new HashMap<>();
    }

    public void addVertex(int vertex) {
        adjVertices.putIfAbsent(vertex, new ArrayList<>());
    }

    public void addEdge(int src, int dest) {
        adjVertices.get(src).add(dest);
    }

    public int getWeight(int src, int dest) {
        return adjVertices.get(src).stream().filter(edge -> edge.dest == dest).findFirst().get().weight;
    }

    private static class Edge {
        int dest;
        int weight;
        public Edge(int dest, int weight) {
            this.dest = dest;
            this.weight = weight;
        }
    }

    /*  Dijkstra's Algorithm
     * ----------------------
     * Space Complexity: O(V)
     * Time Complexity: O(E + VlogV)
     * Finds the shortest path from a source vertex to all other vertices in a weighted graph. Cannot detect negative
     * weight cycles. 
     */
    public void dijkstra(int start) {
        int [] dist = new int[adjVertices.size()];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[start] = 0;

        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> dist[a] - dist[b]);
        pq.add(start);

        while (!pq.isEmpty()) {
            int u = pq.poll();
            for (int v: adjVertices.get(u)) {
                if (dist[v] > dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                    pq.add(v);
                }
            }
        }
    }

    /*  Bellman-Ford Algorithm 
     * -----------------------
     * Space Complexity: O(V)
     * Time Complexity: O(VE)
     * Finds the shortest path from a source vertex to all other vertices in a weighted graph. Can detect negative
     * weight cycles. 
     */
    public void bellmanFord(int start) {
        int [] dist = new int[adjVertices.size()];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[start] = 0;

        for (int i=0; i<adjVertices.size()-1; ++i) {
            for (int vertex=0; vertex<adjVertices.size(); ++vertex) {
                for (int neighbor : adjVertices.get(vertex)) {
                    int newDist = dist[vertex] + getWeight(vertex, neighbor);
                    if (dist[neighbor] > newDist) {
                        dist[neighbor] = newDist;
                    }
                }
            }
        }
        // Check for negative weight cycles
        for (int vertex=0; vertex<adjVertices.size(); ++vertex) {
            for (int neighbor : adjVertices.get(vertex)) {
                int newDist = dist[vertex] + getWeight(vertex, neighbor);
                if (dist[neighbor] > newDist) {
                    System.out.println("Negative weight cycle detected");
                    return;
                }
            }
        }
    }


    public static void main(String[] args) {
        ShortestPath<Integer> g = new ShortestPath<>();
        g.addVertex(1);
        g.addVertex(2);
        g.addVertex(3);
        g.addVertex(4);
        g.addEdge(1, 2);
        g.addEdge(2, 3);
        g.addEdge(3, 1);
        g.addEdge(4, 4);
        g.dijkstra(2);
        System.out.println();
        ShortestPath<Integer> g2 = new ShortestPath<>();
        // Add negative weight cycle
        g2.addVertex(1);
        g2.addVertex(2);
        g2.addVertex(3);
        g2.addEdge(1, 2);
        g2.addEdge(2, 3);
        g2.addEdge(3, 1);
        g2.bellmanFord(1);
        System.out.println();
    }
}