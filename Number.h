

class number {

	virtual number& operator+(number&)=0;
	virtual number& operator-(number&)=0;
	virtual number& operator*(number&)=0;
	virtual number& operator/(number&)=0;

};

class polynomial : number {

private:
	string expression;
	
	polynomial(string a) : expression(a) {}

	polynomial operator+(polynomial&);
	polynomial operator-(polynomial&);
	polynomial operator*(polynomial&);
	polynomial operator/(polynomial&);
};

class irrational : number {

	irrational operator+(irrational&);
	irrational operator-(irrational&);
	irrational operator*(irrational&);
	irrational operator/(irrational&);
};

class integer : number {
	
	private:
		int pure;
		
	integer operator+(integer&);
	integer operator-(integer&);
	integer operator*(integer&);
	integer operator/(integer&);
};

class fraction : number {

	private:
	int num;
	int denom;
	
	fraction(number a, number b) : num(a), denom(b) {} 
	
	fraction operator+(fraction&);
	fraction operator-(fraction&);
	fraction operator(fraction&);
	fraction operator/(fraction&);
};

class log : number {
	
	private:
	int base;
	int pure;
	
	log() : base(0), pure(0) {}
	log(number a, number b) : base(a), pure(b) {}			//Will this generalize and be compatible with all number types? Log of a log solved?

	log operator+(log&);
	log operator-(log&);
	log operator*(log&);
	log operator/(log&);
};