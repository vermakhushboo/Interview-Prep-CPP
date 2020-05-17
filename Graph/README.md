### Graphs

Graphs consist of *nodes* and *edges*. Graphs can be used to represent any networks.

Real life examples: Google Maps, Facebook connections, Social Networking sites etc.

- **Directed Graphs**: Edges directed in a single direction

- **Undirected Graphs:** Edges are bi-directional

#### Graph Representation

- **Adjacency Matrix:** 2-D array of size V*V (V=vertices). Always symmetric for undirected graphs. 

  `adjacency_matrix[i][j] = 1`, in case of unweighted graph

  `adjacency_matrix[i][j] = w`, in case of weighted graph, representing an edge from vertex i to vertex j of weight *w*

  Adjacency matrix is easier to understand and removing or checking an edge takes O(1) time, but consumes V*V space even when there are less edges.

- **Adjacency List:** Graphs can be implemented as an array of lists or vectors. Every index of the array will contain a list/vector containing nodes connected to the node represented by the array index.

  Weighted graphs can also be represented using adjacency list where weights of edges can be represented as list of pairs.
  
  This implementation saves space and adding a vertex is easier but querying like whether edge exists takes O(V) time.
