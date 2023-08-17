//Big Integer Library


#include<iostream>
#include<string>

using namespace std;

template<typename T> class Node{
        public:
        
        T num;
        
        Node*next;
        Node*prev;
        
        Node(T num)
        {
            this->num = num;
            next = NULL;
            prev = NULL;
            
        }
        
        
};

template<typename T> class Stack{
  
  public:
  
  int capacity;
  
  Node<T>*top_nd;
  
  Stack()
  {
      capacity = 0;
      top_nd = NULL;
  }
  
  void push(T k)
  {
      Node<T>*nd = new Node<T>(k);
      
      if(top_nd==NULL)
      top_nd=nd;
      
      else{
          nd->prev = top_nd;
          top_nd->next = nd;
          top_nd = nd;
      }
      
      capacity++;
  }
  
  T pop()
  {
      Node<T>*t = top_nd;
      
      
      top_nd = top_nd->prev;
      capacity--;
      
      T res = t->num;
      
      delete t;
      
      return res;
  }
  
  bool empty()
  {
      if(capacity==0)
      return true;
      
      return false;
  }
  
  int size()
  {
      return capacity;
  }
  
  T top()
  {
      return top_nd->num;
  }
};

int compare(string a,string b)
{
   int n = a.length();
   int m = b.length();

   
  int i=0;
  int j=0;

  while(i<n && a[i]=='0')
  i++;

  while(j<m && b[j]=='0')
  j++;

  if(n-i>m-j) return 1;

  if(n-i<m-j) return -1;


   while(i<n && j<m)
   {
    if(a[i]>b[j])
    return 1;

    if(a[i]<b[j])
    return -1;

    j++;
    i++;
   }

   return 0;
}

void reverse(string &s)
{

    int n = s.length();
    int i=0;
    int j=n-1;

    while(i<j)
    {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
        i++;
        j--;
    }
}

string complement_of_9(string a,int m)
{
   int n = a.length();


   string ans;
   int i=n-1;
  int j=m-1;
   while(i>=0 && j>=0)
   {
    int val = a[i]-'0';

    int res_diff = 9-val;
    ans.push_back(res_diff+'0');
    
    i--;
    j--;
   }

   while(j>=0)
   {
    ans.push_back('9');
    j--;
   }
   

   reverse(ans);
   //cout<<ans<<endl;
   return ans;
}

string division_by_2(string a)
{
  string res_division_2;

  int i =0;
  int n = a.length();
   
   int rem = 0;
  while(i<n)
  {
    int val = rem*10 + (a[i]-'0');
    i++;
    while(i<n && val<2)
    {
      
      int w = a[i]-'0';

      val = val*10 + w;
      i++;

    
      res_division_2.push_back('0');
    
    
  
  }

    int div = val/2;
    
     rem = val%2;
    res_division_2.push_back(div+'0');

  }

  //cout<<res_division_2;

  return res_division_2;
}

string addition(string a,string b)
{
    
  int n = a.length();
  int m = b.length();
 
  int carry=0;
  int i=n-1;
  int j=m-1;

  string result;

  result.append(max(m,n)+1,'0');
   int k = max(m,n)-1;
  
  while(i>=0 && j>=0)
  {
    int val = a[i]-'0';
    int val2 = b[j]-'0';


    int sum = val+val2;
   
    int res = sum + (result[k+1]-'0');
   
    result[k+1] = (res%10) + '0';

    
    result[k] = (res/10) + '0';

    k--;
    i--;
    j--;
  } 
  
  while(i>=0)
  {
    int val = a[i]-'0';
    int sum = val;

    int res = sum + (result[k+1]-'0');
    result[k+1] = (res%10) + '0';

    result[k] = (res/10) + '0';
    k--;
    i--;
   
  }

  while(j>=0)
  {

    int val = b[j]-'0';
    int sum = val;

    int res = sum + (result[k+1]-'0');
    result[k+1] = (res%10) + '0';

    result[k] = (res/10) + '0';
    k--;
    j--;
  
  }
 
  int l=0;

  while(l<result.length() && result[l]=='0')
  {
    
    l++;
  }


   string res_add;

   for(;l<result.length();l++)
   res_add.push_back(result[l]);

  if(res_add.length()==0)
  return "0";

  
  return res_add;
}

string substraction(string a,string b)
{
    if(compare(a,b)==0)
    {
    return "0";
    }


    int n = a.length();
    int w = b.length();
    string r = complement_of_9(b,max(n,w));

    int m = r.length();
 
   

     string result;

  result.append(max(m,n)+1,'0');
   int k = max(m,n)-1;
  
  int i = n-1;
  int j = m-1;
  while(i>=0 && j>=0)
  {
    int val = a[i]-'0';
    int val2 = r[j]-'0';


    int sum = val+val2;
   
    int res = sum + (result[k+1]-'0');
   
    result[k+1] = (res%10) + '0';

    
    result[k] = (res/10) + '0';

    k--;
    i--;
    j--;
  } 
  
  while(i>=0)
  {
    int val = a[i]-'0';
    int sum = val;

    int res = sum + (result[k+1]-'0');
    result[k+1] = (res%10) + '0';

    result[k] = (res/10) + '0';
    k--;
    i--;
   
  }

  while(j>=0)
  {

    int val = r[j]-'0';
    int sum = val;

    int res = sum + (result[k+1]-'0');
    result[k+1] = (res%10) + '0';

    result[k] = (res/10) + '0';
    k--;
    j--;
  
  }

   
  if(result[0]=='1')
  {
    result[0]='0';
    result = addition(result,"1");
  }
    
//   cout<<result<<endl;

  int l=0;

  while(l<result.length() && result[l]=='0')
  {
    
    l++;
  }

  string res_sub;

  for(;l<result.length();l++)
  {
    res_sub.push_back(result[l]);
  }

  if(res_sub.length()==0)
  {
   // cout<<"0"<<endl;
    return "0";
  }

  int count = 0;

  for(int i=0;i<res_sub.length();i++)
  {
    if(res_sub[i]=='9')
    count++;
  }

  if(count == res_sub.length())
  return "0";

 

  return res_sub;

 

}

string multiplication(string a,string b)
{
  int n = a.length();
   int m = b.length();


   int num[n+m];
   for(int i=0;i<n+m;i++)
   num[i]=0;


  


   for(int i=n-1;i>=0;i--)
   {
      for(int j=m-1;j>=0;j--)
      {
        
        int ans = num[i+j+1] + (a[i]-'0')*(b[j]-'0');
        num[i+j+1] =  ans%10;
        
        
        int ans1 = num[i+j] + ans/10;

        num[i+j] = ans1;
      }
   }

   int l=0;
   string mul_res;

   while(l<n+m && num[l]==0)
   {
    l++;
   }

   for(;l<n+m;l++)
   {
    mul_res.push_back(num[l]+'0');
   }

   if(mul_res.length()==0)
   return "0";

   return mul_res;

}

string division(string a,string b)
{

   if(compare(a,b)<0)
   return "0";

   else if(compare(a,b)==0)
   return "1";

   string l = "1";

   string r = a;
  
 
   string ans;

   while(compare(l,r)<=0)
   {
     string add_l_r = addition(l,r); 
    //  cout<<l<<" "<<r<<endl;
     //cout<<add_l_r<<endl;
     string mid = division_by_2(add_l_r);
     //cout<<mid<<endl;
     string multiply_mid_times = multiplication(b,mid);
    // cout<<multiply_mid_times<<endl;
     int compare_result = compare(a,multiply_mid_times);
     
     if(compare_result==0)
     return mid;

     else if(compare_result<0)
     {
        r = substraction(mid,"1");
     }

     else{
       ans = mid;
       l = addition(mid,"1");
     }
   }

  // cout<<ans<<endl;
   return ans;
   
}

void evaluate_factorial(string num)
{
   string fact_num = "1"; 
   string fact_res = "1";
   while(compare(num,fact_num)>=0)
   {
       fact_res = multiplication(fact_res,fact_num);

       fact_num = addition(fact_num,"1");


   }

   cout<<fact_res<<endl;
}

int priority_symbols(char ch)
   {
       if(ch=='+' || ch=='-')
       return 1;

       if(ch=='x' || ch=='/')
       return 2;

       return 0;
   }

string convert_postfix(string exp)
{

   string postfix;
   Stack<char>st;

         int i=0;
         int n = exp.length();
        while(i<n)
        {
            if(exp[i]==' '){
                i++;
                continue;
            }
           if(exp[i]=='+' || exp[i]=='-' || exp[i]=='x' || exp[i]=='/')
           {
              while(st.empty()==false && (priority_symbols(exp[i]) <= priority_symbols(st.top())))
              {
                  postfix.push_back(st.top());
                  st.pop();
              }

              st.push(exp[i]);
              i++;
           }

           else{
               postfix.push_back(exp[i]);
               i++;
               while(i<n && exp[i]!='+' && exp[i]!='-' && exp[i]!='x' && exp[i]!='/' && exp[i]!=' ')
               {
                   postfix.push_back('#');
                   postfix.push_back(exp[i]);
                   i++;
               }
           }
        }
    while(st.empty()==false)
    {
      postfix.push_back(st.top());
      st.pop(); 
    }

        return postfix;


}

void evaluate_postfix(string postfix)
{
    Stack<string>st;

        int i=0;
        int n = postfix.length();

         while(i<n)
         {
            if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='x' || postfix[i]=='/')
            {
                 string val = st.top();
                 st.pop();
                 string val2 = st.top();
                 st.pop();

                 if(postfix[i]=='+')
                 {
                    string res_addition = addition(val2,val);
                    st.push(res_addition);
                 }
                 else if(postfix[i]=='-')
                 {
                    string res_substraction = substraction(val2,val);
                    st.push(res_substraction);
                 }
                 else if(postfix[i]=='x')
                 {
                    string res_multiplication = multiplication(val2,val);
                    st.push(res_multiplication);
                 }
                 else if(postfix[i]=='/')
                 {
                    string res_division = division(val2,val);
                    st.push(res_division);
                 }

                 i++;
            }

            else{
                string k;
                k.push_back(postfix[i]);
                i++;
                while(i<n && postfix[i]=='#')
                {
                    i++;
                    k.push_back(postfix[i]);
                    i++;
                }
                st.push(k);
            }
         }

         cout<< st.top();
}

void evaluate_expression(string exp)
{
  string postfix = convert_postfix(exp);
  
  cout<<postfix<<endl;
  evaluate_postfix(postfix);

//   addition("1","1");
}

void evaluate_exponential(string base,string power)
{

}

void evaluate_gcd(string num1,string num2)
{

}


int main()
{
  
  
   //evaluate_expression("3 + 4 x 4 / 8 ");
  //cout<<division_by_2("493293538920255872941");
   //cout<<division("31453714531697317930342038614491639176715261250697646648119186218074708184397979194637534365855431403309503550859280688992463439176917124526217968147271582960186677685371206538430724994346996092210054503570074091454860052393044206825310997872947755201374913773380699361770046401239506695950260610198348331174585537135935457863113954124590933721033644343139629085062374986532408490353905478355127260504017484055980238133165005500251912179379093108220847358043754072895708017980692181445926430112424244765522814273639284744828515384141299432025359085255861782009111579901046165442062518688031375180033506412922315127339722083690265973976926548639326441218992460006930505469244233969001930291218711162521306270524005062805721802076806517901331057663766750866009937471232187209206745806058920623934938820195572133423080525999396512202256170536212786591286361462483686386023153445266760492951830726764048490429318544300650995664915964777543049563664816121912672452986479737953794877374025757605452161728853692480069598466047524575270836005847154410690652951933633968819704153660642084698509913500764660967009425011792552287753537417739974898162581476485385973006511150727757788919364556579556791827825348721613411700009638953210450631840981816455998278373397216818028043634443808547152634223094803650576059044270113847984083143677193231100944393879918646061326132642487774569922948698238680359596141971574339998781355814896498445155239387895600838069568418471583139116920451474307254823909648744292694422946266120276378277775008906678598823064455246305533289691201165012521349090451671634479233388328104378988479923168857183269168909049698087778906955510265376113110479404350826115989319488107514559001541789729049239288627556687001795920810576806911010174313507128457404965261809654405633205952291766229796751330851863178609900613511790123141855728508554660383591333271638629024858317567240898889949688325205041788438959270283193376236067932396004027521496375555278357091768141032848404344355609870608435746698963304213526015811162113172795653751496732789531135300002242982269857241053772418344673016534959279929583845349515793914866429935800643622476379690640643120052343835404000560737370395980279121442458121838339237165663576187451940563536514540418122575834960649611942039890701691213578129854905125733003701983887353150472427195504742845249673259595380631915997851241803945520265357586849498776071347355014633153515562725442129038947954490883164012248049860015211307126333728876033365681815663588095097531939010691797921769308574004186248566496512631080125633935644169872790179413286139605150153768962696511734065567939176523906023203343128338338878626705026175124335936430621847932724260564649565692916879871888273892555271949560818545425729965186190445862733378740358796999983009241977077630685863714156608393779064638201863367819880087128372657934150349036967586617419836295442239281036077686325160023044757300534368734055942977835627229233910831252301555656540756090424048582909941339983971379890239736285626530445591064542080973125966595483556241853251272278066949610259477724992110434812835387781396285839594917168122672452666418477923078928309976287180866603862829602570684622133971467586577772320508034677958718737986012980635784939042255850555906658731706823325206220521798271392535238148491927341266771132797189840242750082012724084578603759113065343579281120974721700511032334615566636059377813750066734847295079167358388228003949212536644992789051060249809622891806422364653338598852365586088767627103770799041745347200804217630758455117799754438777881698618366483867199739675932452808135709060362711286505985729848283961648726326512558337747984506288453949337406562036894474199257096399750382750092624955242380399862186686485104105138807171114848706986933189185134003504501854614418000322894248826109464318051917459448726098520170597266548958578550195317344371733367827169156715987105170132471298619682715654761451164980140987603316232170848627078875154492807560243863470360983511217256738084488804039250670015811361165091437112058624089365652357063553241282506826516449874959823444569653677937041295991741311487389858375604562490777752593661118747112148412460891750439555564439574947672346921854759822895686582037359694748479348285904338868984548759266986355401548235920883704359362489269501206000730979163836553320443811934716975810488815615772555404367203982774979402367142958899502266947101260615240337501836039110051909618140823480225502940815109305832992636389017168355283131038593961609955463431700716863818050465708128862753280480245123305997040553360302631374079795563556806038132481845301827354515903594228463787754617731445557397141925537118730597062848006776093192397246712953744232877944967247237273180178269584662838786724464725210950728810136835051515382254896158903008345137247596099586961370388200916699176010845652543837450943826218283374852839389885893960473819069869973077735608414595619926293224750229022099887512744188903410152951859712609898421272232810751159622433241804059092401717205783940810270709732769283388620624924043119113051658952606169042006995156131437203960553194821435030337797675017072621081104435285214281341329970490649304440145397223397870076165393005460077036158057036246468231540055880024602558108138523287421144065165564260554202709196114667899609600473419717952573789541386105682147336029667599895768186657775468020021683232616862063769763707729024185530741913305523517761773850879158117552445200053374566522320034312580913632879279769143644903864959880346538716533171270626631580975124155700697821227608191461963028387093625796793222626377070543080765092406555335853736998873434960280213645514181432072153387456290516467099312135450400212666124792721854281646677618997270635055165003653932775209860540951212878499246350314659509553890717877940704382243877425982329361629375643903329365816194568271138658721339381136480239708026859113511500","2355")<<endl;
  // cout<<multiplication("366677867676878","89418183297887158331189146799739705748976236");
  //cout<<addition("3232","32");

    // int choice;
     
    // cin>>choice;
    // string exp;
    // string base;
    // string power;
    // string num1;
    // string num2;
    // string num;

    // switch (choice)
    // {
    //     case 1:
       
    //     cin>>exp;
    //     evaluate_expression(exp);
    //     break;

    //     case 2:
       
         
    //     cin>>base;
    //     cin>>power;

    //     evaluate_exponential(base,power);
    //     break;

    //     case 3:

    //     cin>>num1;
    //     cin>>num2;

    //     evaluate_gcd(num1,num2);
    //     break;

    //     case 4:
       
    //     cin>>num;

    //     evaluate_factorial(num);
    //     break;

    //     default:
    //     cout<<"Choose option in range of 1 to 4"<<endl;
    //     break; 


    // }

   
    

    return 0;
}
