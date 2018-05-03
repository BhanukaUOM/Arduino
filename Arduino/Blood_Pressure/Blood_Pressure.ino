char ReciveData; 
int i[50]; 
int x=-1; 
int y=0; 
int SYS=0; 
int DIA=0; 
int H_R=0; 
int DAY=0;

void setup() {  
  Serial.begin(9600); 
} 

void loop() {   
  Get_Data(); 
} 

void Get_Data() {  
  if (Serial.available()){ 
    ReciveData=Serial.read(); 
    x++; 
  } 
  
  i[x]=ReciveData; 
  
  if(x>9) {
    SYS = ( ((i[0]-48)*100) + ((i[1]-48)*10) + (i[2]-48) );  
    DIA = ( ((i[3]-48)*100) + ((i[4]-48)*10) + ((i[5]-48)*1));  
    H_R = ( ((i[6]-48)*100) + ((i[7]-48)*10) + (i[8]-48) );  
    DAY = ( ((i[9]-48)*10) + ((i[10]-48)) );      
    Serial.print("SYS = ");  
    Serial.print( SYS );  
    Serial.println(" mmHg/kpa");  
    Serial.print("DIA = ");  
    Serial.print( DIA );  
    Serial.println("  mmHg/kpa");    
    Serial.print("H.R = ");  
    Serial.print( H_R );  
    Serial.println(" PLUSE/Min");    
    Serial.print("DAY IS : ");  
    Serial.println( DAY );    
    Serial.println("");  
    Serial.println("************************************************");  
    Serial.println("");  
    x=-1; 
  } 
}
