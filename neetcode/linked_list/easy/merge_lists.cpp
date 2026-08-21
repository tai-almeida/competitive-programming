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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *curr1 = list1, *curr2 = list2, aux = ListNode(0);
        ListNode *merged = &aux;
        while(merged != nullptr && (curr1 != nullptr || curr2 != nullptr)) {
            if(curr1 == nullptr) {
                merged->next = curr2;
                curr2 = curr2->next;
                break;
            } else if(curr2 == nullptr) {
                merged->next = curr1;
                curr1 = curr1->next;
                break;
            } else {
                if(curr1->val >= curr2->val) {
                    merged->next = curr2;
                    curr2 = curr2->next;
                } else {
                    merged->next = curr1;
                    curr1 = curr1->next;
                }
                merged = merged->next;
            }
        }
        return aux.next;
    }

    void printList(ListNode *list) {
        while(list != nullptr) {
            cout << list->val;
            if(list->next != nullptr) {
                cout << " -> ";
            }
            list = list->next;
        }
        cout << endl;
    }
};

int main() {
    Solution s = Solution();
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(5);

    ListNode *merged = s.mergeTwoLists(list1, list2);
    s.printList(merged);
}
