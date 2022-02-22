//
// Created by kirill_kazarin on 18.02.2022.
//

#include "priority_queue.hpp"

namespace h_work {

    template<typename T>
    priority_queue<T>::~priority_queue() noexcept {
        std::destroy(this->mass_of_tree.begin(), this->mass_of_tree.end());
    }

    template<typename T>
    void priority_queue<T>::add_element(T new_element) {
        this->mass_of_tree.push_back(new_element);

        this->lift_to_top_elem(this->mass_of_tree.end()-1);


    }

    template<typename T>
    bool priority_queue<T>::delete_element(T element) {

    	for(auto i=this->mass_of_tree.begin();i<this->mass_of_tree.end();++i){
    		if(*i==element){
    			this->delete_element(i);
    			return true;
    		}
    	}
    	return false;
    }

    template<typename T>
    priority_queue<T>::priority_queue() {
        this->mass_of_tree = new std::vector<T>();
    }

    template<typename T>
    size_t priority_queue<T>::size() noexcept {
        return this->mass_of_tree.size();
    }

    template<typename T>
    bool priority_queue<T>::empty() noexcept {
        return this->mass_of_tree.empty();
    }

    template<typename T>
    priority_queue<T>::priority_queue(std::vector<T> mass) : mass_of_tree(mass) {
    	
        for(auto i=this->mass_of_tree.end()-1;i>this->mass_of_tree.begin();--i){
    			this->move_up_elem(i);	
    	}
    }

    template<typename T>
    T priority_queue<T>::max_elem() noexcept {
        return *this->mass_of_tree.begin();
    }

    template<typename T>
    void priority_queue<T>::move_up_elem(typename std::vector<T>::iterator elem) {

        auto element_itr= elem;

        while (element_itr >this->mass_of_tree.begin()){

            auto parent_element=mass_of_tree.begin() + (distance(mass_of_tree.begin(),element_itr)-1)/2;

            if(*element_itr < *(parent_element)){
                break;
            }

            swap(*(element_itr),*(parent_element));

            element_itr=parent_element;
        }
    }
    
    template<typename T>
    void priority_queue<T>::delete_element(typename std::vector<T>::iterator elem) {

        auto element_itr= elem;
        
        swap(*(elem),*(this->mass_of_tree.end()-1));
        
        this->mass_of_tree.pop_back();
        
        this->move_down_elem(elem);

    }


    template<typename T>
    void priority_queue<T>::move_down_elem(typename std::vector<T>::iterator elem) {

        auto element_itr= elem;
        T elem_value=*elem;

        while (element_itr <this->mass_of_tree.end()){

            auto child1_element=mass_of_tree.begin() + 2*(distance(mass_of_tree.begin(),element_itr))+1;
            auto child2_element=mass_of_tree.begin() + 2*(distance(mass_of_tree.begin(),element_itr))+1;

            if(*element_itr > *(child1_element) &&
                    *element_itr > *(child2_element)){
                break;
            }

            auto max_elem=std::max(std::max(*child1_element,*child2_element),*element_itr);

            swap(*(element_itr),max_elem);

            if (elem_value == *child2_element) {
                element_itr = child2_element;
            } else {
                	element_itr = child1_element;
            }
        }
    }

}
