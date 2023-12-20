package Algorithms.Graphs;

import java.util.*;

public class MinimumTrees {
    private static final int V = 9;

    class Edge implements Comparable<Edge> {
        int src, dest, weight;
        public Edge(int src, int dest, int weight) {
            this.src = src;
            this.dest = dest;
            this.weight = weight;
        }

        public int compareTo(Edge compareEdge) {
            return this.weight - compareEdge.weight;
        }
    }

    int find(int parent[], int i) {
        if(parent[i] == -1) {
            return i;
        }
        return find(parent, parent[i]);
    }

    void union(int parent[], int x, int y) {
        int xset = find(parent, x);
        int yset = find(parent, y);
        parent[xset] = yset;
    }

    int minKey(int key[], Boolean mstSet[]) {
        int min = Integer.MAX_VALUE, min_index = -1;
        for(int v = 0; v < V; ++v) {
            if(mstSet[v] == false && key[v] < min) {
                min = key[v];
                min_index = v;
            }
        }
        return min_index;
    }

    void printMST(int parent[], int graph[][]) {
        System.out.println("Prim's MST: ");
        System.out.println("__________________");
        System.out.println("Edge\tWeight");
        for(int i = 1; i < V; ++i) {
            System.out.println(parent[i] + " - " + i + "\t" + graph[i][parent[i]]);
        }
        System.out.println();
    }

    void primMST(int graph[][]) {
        int parent[] = new int[V];
        int key[] = new int[V];
        Boolean mstSet[] = new Boolean[V];
        Arrays.fill(key, Integer.MAX_VALUE);
        Arrays.fill(mstSet, false);

        key[0] = 0;
        parent[0] = -1;

        for (int count = 0; count < V - 1; ++count) {
            int u = minKey(key, mstSet);
            mstSet[u] = true;
            for (int v = 0; v < V; ++v) {
                if(graph[u][v] != 0 && mstSet[v] == false && graph[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
            }
        }
        printMST(parent, graph);
    }

    void kruskalMST(int graph[][]) {
        int parent[] = new int[V];
        for (int i = 0; i < V; ++i) {
            parent[i] = -1;
        }
        ArrayList<Edge> edges = new ArrayList<>();
        for (int i = 0; i < V; ++i) {
            for (int j = i; j < V; ++j) {
                if(graph[i][j] != 0) {
                    edges.add(new Edge(i, j, graph[i][j]));
                }
            }
        }
        edges.sort(Edge::compareTo);
        Edge result[] = new Edge[V];
        int e = 0, i = 0;
        while (e < V - 1 && i < edges.size()) {
            Edge nextEdge = edges.get(i++);
            int x = find(parent, nextEdge.src);
            int y = find(parent, nextEdge.dest);
            if(x != y) {
                result[e++] = nextEdge;
                union(parent, x, y);
            }
        }
        System.out.println("Kruskal's MST");
        System.out.println("__________________");
        System.out.println("Edge\tWeight");
        for (i = 0; i < e; ++i) {
            System.out.println(result[i].src + " - " + result[i].dest + "\t" + result[i].weight);
        }
        System.out.println();
    }


    void reverseDelete(int graph[][]) {
        int parent[] = new int[V];
        for (int i = 0; i < V; ++i) {
            parent[i] = -1;
        }
        ArrayList<Edge> edges = new ArrayList<>();
        for (int i = 0; i < V; ++i) {
            for (int j = i; j < V; ++j) {
                if(graph[i][j] != 0) {
                    edges.add(new Edge(i, j, graph[i][j]));
                }
            }
        }
        edges.sort(Collections.reverseOrder());
        Edge result[] = new Edge[V];
        int e = 0, i = 0;
        while (e < V - 1 && i < edges.size()) {
            Edge nextEdge = edges.get(i++);
            int x = find(parent, nextEdge.src);
            int y = find(parent, nextEdge.dest);
            if(x != y) {
                result[e++] = nextEdge;
                union(parent, x, y);
            }
        }
        System.out.println("Reverse Delete MST");
        System.out.println("__________________");
        System.out.println("Edge\tWeight");
        for (i = 0; i < e; ++i) {
            System.out.println(result[i].src + " - " + result[i].dest + "\t" + result[i].weight);
        }
        System.out.println();
    }

    public static void main(String[] args) {
        MinimumTrees t = new MinimumTrees();
        int graph[][] = new int[][] { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                                      { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                                      { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                                      { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                                      { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                                      { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                                      { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                                      { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                                      { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
        t.primMST(graph);
        t.kruskalMST(graph);
        t.reverseDelete(graph);
    }
}