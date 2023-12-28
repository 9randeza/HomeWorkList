#include <iostream>

template <typename T>

class List{
	private:
		struct Node{
			Node* next = nullptr;
			Node* prev = nullptr;
			T     data;
		};
		
		Node* first = nullptr;
		Node* last  = nullptr;
		
		int elementsCount = 0;
	public:
		List() = default;
		
		List(const List<T>& l){			//  конструктора копирования
			elementsCount = l.elementsCount;

			for (Node* temp = l.first; temp != nullptr; temp = temp->next){
			PushBack(temp->element);
			}
		}
		
		void PushBack(const T& elem){  //добавление эелемент в конец
			Node* node = new Node( nullptr, last, elem);
			
			if (last != nullptr){
				last->next = node;
			}
			else{
				first = node;
			}
			last = node;
			++elementsCount;
		}
		
		void PopBack(){  //удоление элемента из конца
			if (last != nullptr)
			{
				Node* temp = last;
				last = last->prev;

				if (last != nullptr)
				{
					last->next = nullptr;  
				}

				else
				{
					first = nullptr;
				}

				delete temp;
				elementsCount--;
			}

		}
		
		void PushFront(const T& elem){ 	//добавление элемента в начало
			Node* node = new Node(first, nullptr, elem);

			if (first != nullptr){
				first->prev = node;
			}

			else{
				last = node;
			}

			first = node;
			++elementsCount;
		}
		
		 void PopFront(){  //удоление элемента с начала
			if (first != nullptr)
			{
				Node* temp = first;
				first = first->next;

				if (first != nullptr){
					first->prev = nullptr;
				}
				else{
					last = nullptr;
				}

				delete temp;
				elementsCount--;
			}
		}
		
		 List& operator= (const List& l){
			clear();

			Node* node;
			for (node = l.first; node != nullptr; node = node->next)
			{
				PushBack(node->data); 
			}

			elementsCount = l.elementsCount; 
			
			return *this;
		}
		
		const T& Front()const{ 
			return first->data;
		}


		bool Empty()const{
			return first == nullptr;
		}
		void clear() {
			while (elementsCount > 0) {
				PopFront();
			}
		}
		~List(){  //диструктор
			clear();
    	}
};


    

int main(){
	List<int> l1;
	List<int> l2;
	 l1.PushBack(3);
	 l1.PushBack(7);
	 l2.PushBack(8);
	 l2.PushFront(9);
	while (!l1.Empty())
    {
        std::cout << l1.Front() << std::endl;
        l1.PopFront();
    }
    std::cout << std::endl;
  
	l1.PushFront(9);
	while (!l1.Empty())
    {
        std::cout << l1.Front() << std::endl;
        l1.PopFront();
    }
    std::cout << std::endl;
    l1 = l2;
    
    while (!l1.Empty())
    {
        std::cout << l1.Front() << std::endl;
        l1.PopFront();
    }
}
