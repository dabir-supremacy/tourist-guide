//#include <iostream>
//#include <vector>
//#include <string>
//#include <queue>
//using namespace std;
//
//class vertex
//{
//public:
//	string title;
//
//	vertex(string name)
//	{
//		title = name;
//	}
//};
//
//class WeightedGraph
//{
//private:
//	static const int NULL_EDGE = 0;
//	vector<vertex*> vertices;
//	vector<bool> marks;			// marks[i] is mark for vertices[i]
//	int nmbVertices;
//	int maxVertices;
//	vector< vector<int> > edges;
//
//public:
//	// constructor
//	WeightedGraph(int size)
//	{
//		nmbVertices = 0;
//		maxVertices = size;
//
//		vertices.resize(size);
//		for (int i = 0; i < size; i++)	// init vertices
//			vertices[i] = NULL;
//
//		marks.resize(size);
//
//		int rows = size;
//		int columns = size;
//		edges.resize(rows, vector<int>(columns, 0));
//	}
//
//	bool is_empty()
//	{
//		if (nmbVertices == 0)
//			return true;
//		else
//			return false;
//	}
//
//	bool is_full()
//	{
//		if (nmbVertices == maxVertices)
//			return true;
//		else
//			return false;
//	}
//
//	void add_vertex(vertex* aVertex)
//	{
//		vertices[nmbVertices] = aVertex;
//		for (int i = 0; i < maxVertices; i++)
//		{
//			edges[nmbVertices][i] = NULL_EDGE;
//			edges[i][nmbVertices] = NULL_EDGE;
//		}
//		nmbVertices++;
//	}
//
//	void add_edge(int fromVertex, int toVertex, int weight)
//	{
//		int row;
//		int column;
//
//		row = index_is(vertices[fromVertex]);
//		column = index_is(vertices[toVertex]);
//		edges[row][column] = weight;
//	}
//
//	int weight_is(int fromVertex, int toVertex)
//		// If edge from fromVertex to toVertex exists, returns the weight of edge;
//		// otherwise, returns a special “null-edge” value.
//	{
//		int row;
//		int column;
//
//		row = index_is(vertices[fromVertex]);
//		column = index_is(vertices[toVertex]);
//		return edges[row][column];
//	}
//
//	int index_is(vertex* aVertex)
//	{
//		int i = 0;
//		while (i < nmbVertices)
//		{
//			if (vertices[i] == aVertex)
//				return i;
//			i++;
//		}
//		return -1;
//	}
//
//	//bool has_vertex(vertex* aVertex)
//	//{
//
//	//}
//
//	void clear_marks()
//	{
//		for (int i = 0; i < maxVertices; i++)
//			marks[i] = false;
//	}
//
//	void mark_vertex(vertex* aVertex)
//	{
//		int ix = index_is(aVertex);
//		marks[ix] = true;
//	}
//
//	bool is_marked(vertex* aVertex)
//		// Returns true if vertex is marked; otherwise, returns false.
//	{
//		int index = index_is(aVertex);
//		if (marks[index] == true)
//			return true;
//		else
//			return false;
//	}
//
//	vertex* get_unmarked()
//	{
//		for (int i = 0; i < nmbVertices; i++)
//		{
//			if (marks[i] == false)
//				return vertices[i];
//		}
//		return NULL;
//	}
//
//	void DFS(vertex* aVertex)
//	{
//		int ix, ix2;
//		if (aVertex == NULL) return;
//
//		cout << aVertex->title << " ";
//		ix = index_is(aVertex);
//		marks[ix] = true;
//
//		for (int i = 0; i < nmbVertices; i++)
//		{
//			ix2 = index_is(vertices[i]);
//			if (edges[ix][ix2] != NULL_EDGE)	// if adj vertex
//			{
//				if (marks[i] == false)
//					DFS(vertices[i]);
//			}
//		}
//	}
//
//	void BFS(vertex* aVertex)
//	{
//		int ix, ix2;
//		queue <vertex*> que;
//		ix = index_is(aVertex);
//		marks[ix] = true;
//		que.push(aVertex);
//
//		while (!que.empty())
//		{
//			vertex* node = que.front();
//			que.pop();
//			ix = index_is(node);
//			cout << node->title << " ";
//			for (int i = 0; i < nmbVertices; i++)
//			{
//				ix2 = index_is(vertices[i]);
//				if (edges[ix][ix2] != NULL_EDGE)	// if adj vertex
//				{
//					if (marks[i] == false)
//					{
//						marks[i] = true;
//						que.push(vertices[i]);
//					}
//				}
//			}
//		}
//	}
//
//
//	~WeightedGraph()
//	{
//		for (int i = 0; i < nmbVertices; i++)
//		{
//			delete vertices[i];
//		}
//	}
//};
//
//int main()
//{
//	WeightedGraph AdjMatrixGraph(100);
//
//	vertex* root;
//	vertex* pVertex;
//
//	// Add vertices in memory
//	root = new vertex("1");			// 1
//	AdjMatrixGraph.add_vertex(root);
//	pVertex = new vertex("2");		// 2
//	AdjMatrixGraph.add_vertex(pVertex);
//	pVertex = new vertex("3");		// 3
//	AdjMatrixGraph.add_vertex(pVertex);
//	pVertex = new vertex("4");		// 4
//	AdjMatrixGraph.add_vertex(pVertex);
//	pVertex = new vertex("5");		// 5
//	AdjMatrixGraph.add_vertex(pVertex);
//	pVertex = new vertex("6");		// 6
//	AdjMatrixGraph.add_vertex(pVertex);
//	pVertex = new vertex("7");		// 7
//	AdjMatrixGraph.add_vertex(pVertex);
//
//	// Add edges into memory
//	AdjMatrixGraph.add_edge(1, 2, 30);
//	AdjMatrixGraph.add_edge(1, 3, 15);
//	AdjMatrixGraph.add_edge(1, 4, 10);
//	AdjMatrixGraph.add_edge(2, 4, 25);
//	AdjMatrixGraph.add_edge(2, 5, 60);
//	AdjMatrixGraph.add_edge(2, 1, 30);
//	
//	AdjMatrixGraph.add_edge(3, 4, 40);
//	AdjMatrixGraph.add_edge(3, 6, 20);
//	AdjMatrixGraph.add_edge(3, 1, 15);
//	AdjMatrixGraph.add_edge(4, 1, 10);
//	AdjMatrixGraph.add_edge(4, 2, 25);
//	AdjMatrixGraph.add_edge(4, 3, 40);
//	AdjMatrixGraph.add_edge(4, 7, 35);
//	AdjMatrixGraph.add_edge(5, 2, 60);
//	AdjMatrixGraph.add_edge(5, 7, 20);
//	AdjMatrixGraph.add_edge(6, 3, 20);
//	AdjMatrixGraph.add_edge(7, 5, 20);
//	AdjMatrixGraph.add_edge(7, 4, 35);
//	
//
//	// Print Depth first Search Graph Traversal
//	AdjMatrixGraph.clear_marks();
//	AdjMatrixGraph.DFS(root);
//
//	cout << endl;
//
//	// Print BFS Graph Traversal
//	AdjMatrixGraph.clear_marks();
//	AdjMatrixGraph.BFS(root);
//
//	return 0;
//}