//
// Created by kirill_kazarin on 18.02.2022.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

#ifndef LAB1_PRIORITY_QUEUE_PRIORITY_QUEUE_H
#define LAB1_PRIORITY_QUEUE_PRIORITY_QUEUE_H


namespace h_work {


    template<typename T>
    class priority_queue {

    private:
        std::vector<T> mass_of_tree;

        void move_up_elem(typename std::vector<T>::iterator);

        void move_down_elem(typename std::vector<T>::iterator);

    	void delete_element(typename std::vector<T>::iterator);


    public:

        priority_queue();

        explicit priority_queue(std::vector<T>);

        ~priority_queue() noexcept;

        void add_element(T);

        bool delete_element(T);

        size_t size() noexcept;

        T max_elem() noexcept;

        bool empty() noexcept;

    };
}
#endif //LAB1_PRIORITY_QUEUE_PRIORITY_QUEUE_H
