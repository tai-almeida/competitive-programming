#include <iostream>

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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head, *prev = nullptr, *next;
        while(curr != nullptr) {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        return prev;
    }

    void printList(ListNode *head) {
        ListNode *curr = head;
        while(curr != nullptr) {
            cout << curr->val;

            if(curr->next) {
                cout << " -> ";
            }
            curr = curr->next;
        }
    }
};

int main() {
    Solution s = Solution();

    ListNode *head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);

    ListNode *reversed = s.reverseList(head);
    s.printList(reversed);
    cout << endl;

}