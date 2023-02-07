// TODO
template<class T>
class shared_ptr {
  public:
	shared_ptr() {}
	
	T& operator*() {
        return *_obj_ptr;
	}
	T* operator->() {
        return _obj_ptr;
	}
	bool operator()() {
		return _obj_ptr == nullptr;
	}
	int use_count() const {
		return _ref_counter;
	}
	bool unique() const {
	    return use_count() == 1;	
	}
	friend void swap(shared_ptr p1, shared_ptr p2) {}

  private:
    T* _obj_ptr;
	int _ref_counter = 0;
};

template<class T, class... Args>
shared_ptr<T> make_shared(Args&&... args) {
	return shared_ptr<T>(new T(std::forward<Args>(args)...));
}
	