#ifndef __RECTANGULAR_HPP__
#define __RECTANGULAR_HPP__
    class rectangular{
        private:
            float x_maks;
            float x_min;
            float y_maks;
            float y_min;

        public:
            rectangular(float xmid, float ymid, float length, float width);
            bool operator== (rectangular const &)const;
            rectangular operator+ (rectangular const &);
            rectangular operator- (rectangular const &);
            void operator++ ();
            void operator++(int);
            void operator-- ();
            void operator--(int);
            float operator[](int i);
            void output();
    };
#endif