#ifndef __REDBLACK__
#define __REDBLACK__

#define RED 1
#define BLACK 0

template<class T>
class RedBlack{

    public:
        struct Node
        {
            Node * left_;
            Node * right_;
            Node * parent_;
            T value_;
            bool color_;
        };

        RedBlack();
        ~RedBlack();

        Node getRoot();
        int level(Node * n);

        void insert(const T& value);
        void remove(Node * position);

        void print(Node);
        void preOrder(Node * n);
        void inOrder(Node * n);
        void posOrder(Node * n);

        bool color(Node * n);
        void changeColor(Node * n);
    
    private:
        RedBlack(RedBlack&);
        RedBlack& operator =(Tree&);
    
    private:
        Node * root_;

};


#endif  


    template<class T>
    RedBlack<T>::RedBlack(){
        
    }
    template<class T>
    RedBlack<T>::~RedBlack(){
        
    }

    template<class T>
    RedBlack<T>::getRoot(){
        
    }
    template<class T>
    RedBlack<T>::level(Node * n){
        
    }

    template<class T>
    RedBlack<T>::insert(const T& value){
        
    }
    template<class T>
    RedBlack<T>::remove(Node * position){
        
    }

    template<class T>
    RedBlack<T>::print(Node){
        
    }
    template<class T>
    RedBlack<T>::preOrder(Node * n){
        
    }
    template<class T>
    RedBlack<T>::inOrder(Node * n){
        
    }
    template<class T>
    RedBlack<T>::posOrder(Node * n){
        
    }

    template<class T>
    RedBlack<T>::color(Node * n){
        
    }
    template<class T>
    RedBlack<T>::changeColor(Node * n){
        
    }