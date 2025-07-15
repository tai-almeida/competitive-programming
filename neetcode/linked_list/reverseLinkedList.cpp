#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int valor;
    ListNode* prox;

    // construtores da linked list
    ListNode() : valor(0), prox(nullptr) {};
    ListNode(int valor) : valor(valor), prox(nullptr) {};
    ListNode(int valor, ListNode *prox) : valor(valor), prox(prox) {};
};

class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            // verifica lista vazia
            if(head == nullptr) {
                return nullptr;
            }

            // percorre até o fim da lista
            ListNode *prev = nullptr;
            ListNode *no_atual = head;
            int counter = 0;

            while(no_atual) {
                ListNode* temp = no_atual->next;
                no_atual->next = prev;
                prev = no_atual;
                no_atual = temp;
            }

        return prev;
        }
};
