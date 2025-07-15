#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {};
    ListNode(int val) : val(val), next(nullptr) {};
    ListNode(int val, ListNode *next) : val(val), next(next) {};
};

class Solution {
    public:

    ListNode* mergeTwoLists(ListNode *headList1, ListNode *headList2) {
        ListNode* atualLista1 = headList1;
        ListNode* atualLista2 = headList2;

        // ponteiro cabeça que aponta para o endereço do primeiro nó
        ListNode *head = new ListNode();
        ListNode *novaLista = head;

        if(!atualLista1 && !atualLista2) {
            return nullptr;
        } else if (!atualLista1) {
            return atualLista2;
        } else if(!atualLista2) {
            return atualLista1;
        }

        while(atualLista1 || atualLista2) {
            if(!atualLista1)  {
                novaLista->next = new ListNode(atualLista2->val);
                atualLista2 = atualLista2->next;

            } else if(!atualLista2) {
                novaLista->next = new ListNode(atualLista1->val);
                atualLista1 = atualLista1->next;

            }
            else if(atualLista2->val < atualLista1->val) {
                novaLista->next = new ListNode(atualLista2->val);

                atualLista2 = atualLista2->next;
            } else {
                novaLista->next = new ListNode(atualLista1->val);

                atualLista1 = atualLista1->next;
            }
            novaLista = novaLista->next;
        
        }
        return head->next;
        
    }

};

int main() {
    Solution sol;
    ListNode *lista1 = new ListNode(1);
    ListNode *lista2 = new ListNode(2);

    ListNode *novaListaMergeada = sol.mergeTwoLists(lista1, lista2);
    
}