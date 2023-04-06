#include "LinkedList.h"
#ifndef __STACK__
#define __STACK__

#include <iostream>
using namespace std;

//1. 템플릿 클래스로 확장해야함
//2. Stack형식으로 Delete 함수 재정의해야함
//주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함

//LinkedList class를 상속받음
template <typename T>//Stack 클래스 템플릿 사용 선언
class Stack : public LinkedList<T>{ //linkedList<T> 클래스 상속받음
	public:
		bool Delete (T &element){//T타입 변수 사용
			//first가 0이면 false반환
			if (this->first == 0)
				return false;

			// LinkedList와 달리 Stack은 current가 가리키는 곳을 삭제
			Node<T>* current = this->first;//current 현재 스택의 맨앞 노드를 가리키는 포인터가 됨
			this->first = this->first->link;//맨앞원소 제거
			element = current->data;//삭제된 데이터 저장
			delete current;//할당된 메모리 해제
			this->current_size--;//스택의 크기-1
			return true;//삭제 성공
			}
};
#endif
