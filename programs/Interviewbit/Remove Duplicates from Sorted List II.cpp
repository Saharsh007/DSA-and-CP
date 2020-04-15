/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 #define debug4(a,b,c,d) cout<<a<<"->"<<b<<"->"<<c<<"->"<<d<<"\n"

ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A == NULL || A->next == NULL) 
        return A;
    ListNode* prev = A;
    ListNode* curr = A;
    int flag = 0;
    
    while(curr->next != NULL){
        debug4(curr->val,A->val,A->next->val,flag);
        // if(curr->val == curr->next->val){
        //     flag = 1;
            while(curr->val == curr->next->val){
                curr->next = curr->next->next;
                flag = 1;
            }
                
        // }
        // else {
            // repetation
            if(flag == 1){
                
                // if last element has multiples
                if(curr->next == NULL) {
                    ListNode* temp = A;
                    while(temp->next->next != NULL)
                        temp = temp->next;
                    temp->next = NULL;
                }
                //for first element
                else if(curr == prev){ 
                    if(prev == A) A = curr->next;
                    prev = curr->next;
                    curr = prev;
                }
                // for other elements
                else{
                    prev->next = prev->next->next;
                    curr = prev->next;
                }
                flag = 0; 
            }
            // no repetation
            else{
                prev = curr;
                curr = curr->next;
            }
        // }
        debug4(curr->val,A->val,A->next->val, bool(A->next == curr) );

    }
    // cout<<prev->val;
    if(flag == 1)
     {
        prev->next = NULL;
     }
    return A;
    
}
