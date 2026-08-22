#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> visited_nodes;
        ListNode *curr = head;

        while(curr != nullptr) {
            if(visited_nodes.count(curr)) {
                return true;
            }
            visited_nodes.insert(curr);
            curr = curr->next;
        }
        return false;
    }
};


int main() {
    Solution s = Solution();
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4, head->next);

    cout << s.hasCycle(head) << endl;
}
