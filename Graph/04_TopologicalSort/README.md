Topological Sort:
                - Directed acyclic graph (DAG) hona hi chaiye.
                - u->v ans is u comes first before v.
                - 0 -> 1 -> 2 than 0,1,2
            
            0-> 1,2
            1-> 3
            2-> 3
            3-> 

            than exist multipul answers: i) 0 2 1 3
                                        ii) 0 1 2 3

             4>5->0>1->2->3  : 4 5 0 1 2 3    we start from 0 then 0 1 2 3  so  
        
        we traverse in visited array 
        i) if not visited than mark visited and push ans