//
//  Arc.h
//  Cycle_Basis_PF
//
//  Created by Sumiran on 18/06/2014.
//  Copyright (c) 2014 NICTA. All rights reserved.
//

#ifndef Cycle_Basis_PF_Arc_h
#define Cycle_Basis_PF_Arc_h
#include <gravity/Node.h>
#include <gravity/types.h>
#include <assert.h>
#include <string>
#include <vector>


class Arc{
public:
    int _id;
    std::string _name;
    std::string _type_name="Arc";
    Node* _src;
    Node* _dest;
    double _weight;
    bool _active = true;
    bool _parallel = false;
    bool _imaginary = false;
    int _free = false;
    std::vector<Node*> _intersection; // intersection of node _src and node _dest
    std::vector<gravity::index_pair*> _intersection_clique; // useful for clique tree 

    /* @brief Returns the neighbour of n if n is a node of the arc, null otherwise */
    Node* neighbour(Node* n);
    
//  bool in_cycle;
//  Path* horton_path;
    
    
 /* @brief Returns the neighbour of n if n is a node of the arc, null otherwise */
 //   Node* neighbour(Node* n);
    
    Arc();
    Arc(std::string name);
    virtual ~Arc();
    Arc(Node* s, Node* d);
    Arc(Node* s, Node* d, double weight);
    Arc* clone();
    
    /* Connects the current arc to its source and destination, adding itself to the list of branches in these nodes */
    void connect();
    
    void print();
    
    std::vector<gravity::index_pair*> get_intersection_clique();
};




#endif
