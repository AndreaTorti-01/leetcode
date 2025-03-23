// very slow but understandable solution

#include <algorithm>
#include <list>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
  public:
    // extracts vector of nodes connected to x and removes them from graphRepr
    vector<int> extractConnectedNodes(list<pair<int, int>> &graphRepr, int x)
    {
        vector<int> connectedNodes;
        auto it = graphRepr.begin();

        while (it != graphRepr.end())
        {
            if (it->first == x)
            {
                connectedNodes.push_back(it->second);
                it = graphRepr.erase(it);
            }
            else if (it->second == x)
            {
                connectedNodes.push_back(it->first);
                it = graphRepr.erase(it);
            }
            else
            {
                ++it;
            }
        }

        return connectedNodes;
    }

    // returns the number of intersecting elements between a and b
    int intersect(vector<int> &a, vector<int> &b)
    {
        int result = 0;
        unordered_set<int> seen;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for (const auto &el : a)
        {
            if (seen.insert(el).second)
            { // if new (correctly inserted)
                if (binary_search(b.begin(), b.end(), el))
                {
                    result++;
                }
            }
        }
        return result;
    }

    int numberOfComponents(vector<vector<int>> &properties, int k)
    {
        const int graphSize = properties.size();
        vector<int> graphIndices(graphSize);
        for (int i = 0; i < graphSize; i++)
        {
            graphIndices[i] = i;
        }

        list<pair<int, int>> graphRepr;
        for (int i = 0; i < graphSize; i++)
        {
            for (int j = i + 1; j < graphSize; j++)
            {
                if (intersect(properties[i], properties[j]) >= k)
                {
                    graphRepr.push_back({i, j});
                }
            }
        }

        int groups = 0;

        while (!graphIndices.empty()) {
            groups++;

            // get current node
            int currentNode = graphIndices.back();
            graphIndices.pop_back();
            
            // process all connected nodes
            vector<int> nodesToProcess = {currentNode};
            while (!nodesToProcess.empty()) {
                // same algorithm as above but no group count increase
                int node = nodesToProcess.back();
                nodesToProcess.pop_back();
                
                vector<int> connected = extractConnectedNodes(graphRepr, node);
                for (int connectedNode : connected) {
                    auto it = find(graphIndices.begin(), graphIndices.end(), connectedNode);
                    if (it != graphIndices.end()) {
                        nodesToProcess.push_back(connectedNode);
                        graphIndices.erase(it);
                    }
                }
            }
        }
        return groups;
    }
};