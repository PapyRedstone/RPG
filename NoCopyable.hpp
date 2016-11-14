#ifndef NO_COPYABLE_HPP
#define NO_COPYABLE_HPP

class NoCopyable{
public:
	NoCopyable();
	virtual ~NoCopyable() =0;

	NoCopyable(const NoCopyable&) =delete;
	NoCopyable& operator=(const NoCopyable&) =delete;
};

#endif