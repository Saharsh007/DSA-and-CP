/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 #define f(i,a,b) for(long long i=a;i<b;i++)

ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if(A == NULL || A->next == NULL) return A;
    ListNode* prev;
    ListNode* current = A;
    ListNode* nex;
    
    //time pass
    int kk = 100;
    while(kk != 0) kk--;
    
    f(i,0,B-2){
        current = current->next;
    }
    prev = current;
    if(B-2>=0)
        current = current->next;
    nex = current->next;
    if(B-2 < 0)
        prev = NULL;

    ListNode* hold1 = prev;
    ListNode* hold2 = current;
    f(i,0,C-B){
        // cout<<"hey\n";
        current->next = prev;
        prev = current;
        current = nex;
        nex = nex->next;
    }
    current->next = prev;
    
    if(hold1 != NULL)
        hold1->next = current;
    hold2->next = nex;
    
    if(hold1 == NULL)
        return current;
    
    return A;
    
}
