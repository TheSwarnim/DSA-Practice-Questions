st.pop();

                    int x=st.top()-'0';
                    int y=c-'0';

                    int tempAns=x*y;

                    st.pop(); //pop x
                    st.push(tempAns+'0'); //push tempAns