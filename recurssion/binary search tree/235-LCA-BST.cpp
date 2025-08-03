if ((root->val > p->val && root->val < q->val) || 
            (root->val < p->val && root->val > q->val))
            return root;