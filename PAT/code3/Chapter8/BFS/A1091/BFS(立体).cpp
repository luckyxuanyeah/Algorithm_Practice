#include "iostream"
#include "queue"
using namespace std;

struct node{
	int x, y, z;
};

int M, N, L, T;
int Edge[1290][130][61];
int X[6] = {0,0,0,0,1,-1};
int Y[6] = {0,0,1,-1,0,0};
int Z[6] = {1,-1,0,0,0,0};
bool inq[1290][130][61] = { false };

bool judge(int x, int y, int z)
{
	if (x < 0 || x >= M || y < 0 || y >= N || z < 0 || z >= L)
		return false;
	if (inq[x][y][z] == true || Edge[x][y][z] == 0)
		return false;
	return true;
}

int BFS(int a,int b,int c)
{
	int number = 0;
	queue<node> q;
	node Node;
	Node.x = a, Node.y = b, Node.z = c;
	q.push(Node);
	inq[a][b][c] = true;
	while (!q.empty())
	{
		node temp=q.front();
		q.pop();
		number++;
		for (int i = 0; i < 6; i++)
		{
			int newX = temp.x + X[i];
			int newY = temp.y + Y[i];
			int newZ = temp.z + Z[i];
			if (judge(newX, newY, newZ) == true)
			{
				node now;
				now.x = newX, now.y = newY, now.z = newZ;
				q.push(now);
				inq[newX][newY][newZ] = true;
			}
		}
	}
	return number;
}

int main()
{
	cin >> M >> N >> L >> T;
	for (int l = 0; l < L; l++)
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
				cin >> Edge[i][j][l];
		}
	}
	int ans = 0;
	for (int l = 0; l < L; l++)
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (inq[i][j][l] == false && Edge[i][j][l] == 1)
				{
					int temp=BFS(i, j, l);
					if (temp >= T)
						ans += temp;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
