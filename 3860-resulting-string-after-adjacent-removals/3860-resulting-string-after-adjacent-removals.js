/**
 * @param {string} s
 * @return {string}
 */
var resultingString = function(s) {

    let st = [];
        for(let i = 0; i< s.length; i++)
        {

            if(st.length==0)
            {
                st.push(s[i]); continue;
            }
let char1  = st[st.length-1];
let char2 = s[i];
let diff = Math.abs(char1.charCodeAt(0) - char2.charCodeAt(0));
            if(diff == 1 || s[i] == 'a' && st[st.length-1]=='z' || s[i] == 'z' && st[st.length-1]=='a')
            {

                st.pop();
                
            }
            else
            {
                st.push(s[i]);
            }
        }
        let ans  ="";
        while(st.length>0)
        {
            ans+=(st.pop()); 
        }
        
        
       
        return ans.split("").reverse().join("");
    
};