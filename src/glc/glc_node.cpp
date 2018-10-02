#include <glc/glc_node.h>

namespace glc{

  Node::Node(int _card_omega, 
       int _control_index, 
       double _cost, 
       double _cost_to_go, 
       const std::valarray<double>& _state, 
       double _time,
       const std::shared_ptr<Node> _parent): 
       children(_card_omega), 
       cost(_cost), 
       merit(_cost_to_go+_cost), 
       time(_time), 
       parent(_parent), 
       state(_state), 
       u_idx(_control_index){
  }
  
  bool NodeMeritOrder::operator()(const std::shared_ptr<Node>& node1, const std::shared_ptr<Node>& node2){
    return node1->merit>node2->merit;//negation so top of queue is min not max     
  }
  
}//namespace glc