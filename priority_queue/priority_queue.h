//
// Created by kirill_kazarin on 18.02.2022.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

#ifndef LAB1_PRIORITY_QUEUE_PRIORITY_QUEUE_H
#define LAB1_PRIORITY_QUEUE_PRIORITY_QUEUE_H

namespace h_work{

    template<typename T>
    class priority_queue{

    private:

        std::vector<T> mass_of_tree;

        void move_up_elem(typename std::vector<T>::iterator elem) {

            auto element_itr = elem;

            while (element_itr > this->mass_of_tree.begin()) {

                auto parent_element = mass_of_tree.begin() + (distance(mass_of_tree.begin(), element_itr) - 1) / 2;

                if (*element_itr < *(parent_element)) {
                    break;
                }
                std::swap(*(element_itr), *(parent_element));

                element_itr = parent_element;
            }
        }

        void move_down_elem(typename std::vector<T>::iterator elem) {

            auto element_itr = elem;

            while (this->size() >= (size_t)(2 * (distance(mass_of_tree.begin(), element_itr))+1)) {

                auto child1_element = mass_of_tree.begin() + 2 * (distance(mass_of_tree.begin(), element_itr)) + 1;
                auto child2_element = mass_of_tree.begin() + 2 * (distance(mass_of_tree.begin(), element_itr)) + 2;


                auto max_elem = (child2_element==mass_of_tree.end()) ? std::max(*child1_element, *element_itr)
                        : std::max(std::max(*child1_element, *child2_element), *element_itr);

                if (max_elem == *child1_element && child1_element < mass_of_tree.end()) {

                    std::swap(*(element_itr), *(child1_element));
                    element_itr = child1_element;
                    continue;

                } else if(max_elem == *child2_element && child2_element < mass_of_tree.end()){

                    std::swap(*(element_itr), *(child2_element));
                    element_itr = child2_element;
                    continue;
                } else {
                    break;
                }

            }
        }

        void delete_element(typename std::vector<T>::iterator elem) {

            std::swap(*(elem), *(this->mass_of_tree.end() - 1));
            this->mass_of_tree.pop_back();
            this->move_down_elem(elem);
        }

    public:

        void clear(){
            this->mass_of_tree.clear();
        }

        priority_queue() {
            this->mass_of_tree = std::vector<T>();
        }


        size_t size() noexcept {
            return this->mass_of_tree.size();
        }

        bool empty() noexcept {
            return this->mass_of_tree.empty();
        }

        explicit priority_queue(std::vector<T> mass) noexcept : mass_of_tree(mass) {

            for (auto i = this->mass_of_tree.end() - 1; i > this->mass_of_tree.begin(); --i) {
                this->move_up_elem(i);
            }
        }

        T max_elem() noexcept {
            return *this->mass_of_tree.begin();
        }

        typename std::vector<T>::const_iterator max_elem_iterator() noexcept {
            return this->mass_of_tree.cbegin();
        }

        ~priority_queue() noexcept {
            this->mass_of_tree.clear();
        }

        void add_element(T new_element) {
            this->mass_of_tree.push_back(new_element);

            this->move_up_elem(this->mass_of_tree.end() - 1);
        }

        bool delete_element(T element) {

            for (auto i = this->mass_of_tree.begin(); i < this->mass_of_tree.end(); ++i) {
                if (*i == element) {
                    this->delete_element(i);
                    return true;
                }
            }
            return false;
        }

        void pop(){
            this->delete_element(this->mass_of_tree.begin());
        }
    };
}
#endif //LAB1_PRIORITY_QUEUE_PRIORITY_QUEUE_H
