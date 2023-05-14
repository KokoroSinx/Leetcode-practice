//
//  main.cpp
//  leetcode 1 using hashmap
//
//  Created by Shionji Yuuko on 2023/5/14.
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode();
    ListNode(int x);
    ListNode(int x, ListNode *next);
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> a;
        vector<int> b(2,-1);
        for(int i = 0; i < nums.size(); i++){
            a.insert(map<int,int>::value_type(nums[i],i));
        }
        for(int i = 0; i < nums.size(); i++){
            if(a.count(target-nums[i]) > 0 && a[target-nums[i]] != i){
                b[0] = i;
                b[1] = a[target - nums[i]];
                break;
            }
        }
        return b;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            int addition = (l1->val + l2->val) / 10;
            ListNode *head = new ListNode((l1->val + l2->val) % 10);
            ListNode *pre = head;
            l1 = l1->next;
            l2 = l2->next;
            while(l1 != NULL && l2 != NULL){
                int val = l1->val + l2->val + addition;
                addition = val / 10;
                ListNode *cur = new ListNode(val % 10);
                pre->next = cur;
                pre = cur;
                l1 = l1->next;
                l2 = l2->next;
            }
            ListNode *l = (l1 == NULL ? l2 : l1);
            while(l != NULL){
                int val = l->val + addition;
                addition = val / 10;
                l->val = val % 10;
                pre->next = l;
                pre = l;
                l = l->next;
            }
            if(addition == 1) pre->next = new ListNode(1);
            return head;
    }};
    
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
