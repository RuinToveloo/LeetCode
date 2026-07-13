#include <string>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<string>> ans;

    struct Node {
        string name;
        string serial;
        bool drop = false;
        map<string, Node*> children;
        Node(string _name) : name(_name) {}
    };

    unordered_map<string, int> count;

    string serialize(Node* cur) {
        if (cur->children.empty()) return "";
        string s = "(";
        for (auto& [name, child] : cur->children) {
            s += name + serialize(child) + ")(";
        }
        s = s.substr(0, s.size() - 1);
        count[s]++;
        cur->serial = s;
        return s;
    }

    void markDrop(Node* cur) {
        for (auto& [name, child] : cur->children) {
            if (count[child->serial] > 1) {
                child->drop = true;
            } else {
                markDrop(child);
            }
        }
    }

    void collect(Node* cur, vector<string>& path) {
        for (auto& [name, child] : cur->children) {
            if (child->drop) continue;
            path.push_back(name);
            ans.push_back(path);
            collect(child, path);
            path.pop_back();
        }
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node* root = new Node("");
        for (auto& p : paths) {
            Node* cur = root;
            for (auto& s : p) {
                if (cur->children.find(s) == cur->children.end()) {
                    cur->children[s] = new Node(s);
                }
                cur = cur->children[s];
            }
        }
        serialize(root);
        markDrop(root);
        vector<string> path;
        collect(root, path);
        return ans;
    }
};