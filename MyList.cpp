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
		
		void PushBack(const T& elem){
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
		
		void PopBack(){
			if (last != nullptr)
			{
				Node* temp = last;
				last = last->prev;

				if (last != nullptr){
					last->next = nullptr;
				}

				else{
					first = nullptr;
				}

				delete temp;
				elementsCount--;
			}

		}
		
		const T& Front()const{
			return first->data;
		}


		bool Empty()const{
			return first == nullptr;
		}
		

};


    

int main(){
	List<int> l1;
	 l1.PushBack(3);
	  while (!l1.Empty())
    {
        std::cout << l1.Front() << std::endl;
        l1.PopBack();
    }
}
