/* Buttons to USB Keyboard Example - Special Media Player Keys

   You must select Keyboard from the "Tools > USB Type" menu

   This example code is in the public domain.
*/

#include <Bounce.h>

// Create Bounce objects for each button.  The Bounce object
// automatically deals with contact chatter or "bounce", and
// it makes detecting changes very simple.
Bounce button0 = Bounce(0, 10);
Bounce button1 = Bounce(1, 10);  // 10 ms debounce time is appropriate
Bounce button2 = Bounce(2, 10);  // for most mechanical pushbuttons
Bounce button3 = Bounce(3, 10);
Bounce button4 = Bounce(4, 10);  // if a button is too "sensitive" 
Bounce button5 = Bounce(5, 10);  // you can increase this time.
Bounce button6 = Bounce(6, 10);
Bounce button7 = Bounce(7, 10);
Bounce button8 = Bounce(8, 10);



void setup() {
  // Configure the pins for input mode with pullup resistors.
  // The pushbuttons connect from each pin to ground.  When
  // the button is pressed, the pin reads LOW because the button
  // shorts it to ground.  When released, the pin reads HIGH
  // because the pullup resistor connects to +5 volts inside
  // the chip.
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
}

void loop() {
  // Update all the buttons.  There should not be any long
  // delays in loop(), so this runs repetitively at a rate
  // faster than the buttons could be pressed and released.
  button0.update();
  button1.update();
  button2.update();
  button3.update();
  button4.update();
  button5.update();
  button6.update();
  button7.update();
  button8.update();

  // Check each button for "falling" edge.
  // falling = high (not pressed - voltage from pullup resistor)
  //           to low (pressed - button connects pin to ground)
  //BUTTON 1 @ PIN0 INPUTS 20 CHARACTER PASS CODE
  if (button0.fallingEdge()) {
    Keyboard.print("M87%43553^5c!37ME8v3");
    Keyboard.press(KEY_ENTER);
    Keyboard.release(KEY_ENTER);
    delay(80); 
  }
    //BUTTON 2 @ PIN1 RUNS IPCONFIG AND PING IN A CMD WINDOW
  if (button1.fallingEdge()) {
    Keyboard.press(KEY_LEFT_GUI);  
    Keyboard.press(KEY_R);
    Keyboard.releaseAll();
    //Keyboard.release(KEY_LEFT_GUI);
    //Keyboard.release(KEY_R);
    delay(80);
    Keyboard.print("cmd");
    Keyboard.press(KEY_ENTER);
    Keyboard.releaseAll();
    delay(80);
    Keyboard.press(KEY_LEFT_GUI);  
    Keyboard.press(KEY_RIGHT);
    Keyboard.releaseAll();
    //Keyboard.release(KEY_LEFT_GUI);
    //Keyboard.release(KEY_R);
    delay(80);
    Keyboard.print("ipconfig");
    Keyboard.press(KEY_ENTER);
    Keyboard.releaseAll();
    delay(80);
    Keyboard.print("ping 8.8.8.8");
    Keyboard.press(KEY_ENTER);
    Keyboard.releaseAll();
    delay(80); 
  }

      //BUTTON 3 @ PIN2 CREATE LOCAL USER AND GIVES ADMIN PRIVILEDGE
  if (button2.fallingEdge()) {
    delay(2000);
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.releaseAll();
    delay(1500);
    //open cmd with admin priviledge
    Keyboard.print("cmd");
    delay(3000);
    Keyboard.press(KEY_RIGHT_CTRL);
    Keyboard.press(KEY_RIGHT_SHIFT);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    delay(5000);
    Keyboard.press(KEY_LEFT_ARROW);
    Keyboard.releaseAll();
    delay(3000);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    delay(2000);
    //add user ['NEO' is the username and '1234qwer!@#$QWER' is the password]
    Keyboard.print("net user /add neo 1234qwer!@#$QWER");
    delay(3000);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    delay(3000);
   
    //give the user admin priviledge
    Keyboard.print("net localgroup administrators neo /add");
    delay(3000);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    delay(3000);
  }

  // BUTTON 4 @ PIN 3 CHANGES DESKTOP BACKGROUND
  if (button3.fallingEdge()) {
    Keyboard.press(KEY_LEFT_GUI);  
    Keyboard.press(KEY_R);

    Keyboard.release(KEY_LEFT_GUI);
    Keyboard.release(KEY_R);
    delay(100);
    
    Keyboard.print("powershell");
    Keyboard.press(KEY_ENTER);
    Keyboard.release(KEY_ENTER);
    delay(100);

    Keyboard.print("mkdir C:\\temp\\");
    Keyboard.press(KEY_ENTER);
    Keyboard.release(KEY_ENTER);
    delay(100);

    Keyboard.print("wget http://www.hdwallpaper.nu/wp-content/uploads/2015/02/John-Cena-Wallpaper_002.jpg -outfile C:\\temp\\bg.jpg");
    Keyboard.press(KEY_ENTER);
    Keyboard.release(KEY_ENTER);
    delay(100);
    Keyboard.print("reg add 'HKEY_CURRENT_USER\\Control Panel\\Desktop' /v Wallpaper /t REG_SZ /d C:\\temp\\bg.jpg /f");
    Keyboard.press(KEY_ENTER);
    Keyboard.release(KEY_ENTER);
    delay(500);
    Keyboard.print("RUNDLL32.EXE user32.dll,UpdatePerUserSystemParameters");
    Keyboard.press(KEY_ENTER);
    Keyboard.release(KEY_ENTER);
      delay(100);
        Keyboard.print("RUNDLL32.EXE user32.dll,UpdatePerUserSystemParameters");
    Keyboard.press(KEY_ENTER);
    Keyboard.release(KEY_ENTER);
    delay(500);
  Keyboard.print("exit"); 
  Keyboard.press(KEY_ENTER);
  Keyboard.release(KEY_ENTER);
  }

  //BUTTON 5 @ PIN 4 LOCK SCREEN
  if (button4.fallingEdge()) {
    Keyboard.press(KEY_LEFT_GUI);  
    Keyboard.press(KEY_L);

    Keyboard.press(KEY_RETURN);

  }

  //BUTTON 6 @ PIN 5 ATTEMPTS TO OPEN ADMIN CMD PROMPT
  if (button5.fallingEdge()) {
    delay(500);
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.releaseAll();
    delay(500);
    //open cmd with admin priviledge
    Keyboard.print("cmd");
    delay(500);
    Keyboard.press(KEY_RIGHT_CTRL);
    Keyboard.press(KEY_RIGHT_SHIFT);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    delay(500);
    Keyboard.press(KEY_LEFT_ARROW);
    Keyboard.releaseAll();
    delay(500);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    delay(500);
  }

  //BUTTON 7 @ PIN 6 Opens simple CMD window
  if (button6.fallingEdge()) {
    Keyboard.press(KEY_LEFT_GUI);  
    Keyboard.press(KEY_R);
    Keyboard.releaseAll();

   // Keyboard.release(KEY_LEFT_GUI);
   // Keyboard.release(KEY_R);
    delay(500);
    
    Keyboard.print("cmd");
    Keyboard.press(KEY_ENTER);
    Keyboard.release(KEY_ENTER);
    delay(500);
  }

  //BUTTON 8 @ PIN 7 Opens windows explorer to sysinternals live 
  if (button7.fallingEdge()) {
    Keyboard.press(KEY_LEFT_GUI);  
    Keyboard.press(KEY_E);
    Keyboard.releaseAll();
    delay(500);
    Keyboard.press(KEY_LEFT_ALT);  
    Keyboard.press(KEY_D);
    Keyboard.releaseAll();
    delay(500);
    Keyboard.print("\\\\live.sysinternals.com\\tools");
    delay(500);
    Keyboard.press(KEY_ENTER);
    Keyboard.release(KEY_ENTER);
  }

    //BUTTON 9 @ PIN 8 Opens notepad.exe and prints the Decleration of Independance
  if (button8.fallingEdge()) {
    Keyboard.press(KEY_LEFT_GUI);  
    Keyboard.press(KEY_R);
    Keyboard.releaseAll();
    delay(500);
    Keyboard.print("notepad.exe");
    Keyboard.press(KEY_ENTER);
    Keyboard.release(KEY_ENTER);
    delay(500);
    Keyboard.print("When, in the course of human events, it becomes necessary for one people to dissolve the political bonds which have connected them with another, and to assume among the powers of the earth, the separate and equal station to which the laws of nature and of nature's God entitle them, a decent respect to the opinions of mankind requires that they should declare the causes which impel them to the separation. We hold these truths to be self-evident, that all men are created equal, that they are endowed by their Creator with certain unalienable rights, that among these are life, liberty and the pursuit of happiness. That to secure these rights, governments are instituted among men, deriving their just powers from the consent of the governed. That whenever any form of government becomes destructive to these ends, it is the right of the people to alter or to abolish it, and to institute new government, laying its foundation on such principles and organizing its powers in such form, as to them shall seem most likely to effect their safety and happiness. Prudence, indeed, will dictate that governments long established should not be changed for light and transient causes; and accordingly all experience hath shown that mankind are more disposed to suffer, while evils are sufferable, than to right themselves by abolishing the forms to which they are accustomed. But when a long train of abuses and usurpations, pursuing invariably the same object evinces a design to reduce them under absolute despotism, it is their right, it is their duty, to throw off such government, and to provide new guards for their future security. -- Such has been the patient sufferance of these colonies; and such is now the necessity which constrains them to alter their former systems of government. The history of the present King of Great Britain is a history of repeated injuries and usurpations, all having in direct object the establishment of an absolute tyranny over these states. To prove this, let facts be submitted to a candid world. He has refused his assent to laws, the most wholesome and necessary for the public good. He has forbidden his governors to pass laws of immediate and pressing importance, unless suspended in their operation till his assent should be obtained; and when so suspended, he has utterly neglected to attend to them. He has refused to pass other laws for the accommodation of large districts of people, unless those people would relinquish the right of representation in the legislature, a right inestimable to them and formidable to tyrants only. He has called together legislative bodies at places unusual, uncomfortable, and distant from the depository of their public records, for the sole purpose of fatiguing them into compliance with his measures. He has dissolved representative houses repeatedly, for opposing with manly firmness his invasions on the rights of the people. He has refused for a long time, after such dissolutions, to cause others to be elected; whereby the legislative powers, incapable of annihilation, have returned to the people at large for their exercise; the state remaining in the meantime exposed to all the dangers of invasion from without, and convulsions within. He has endeavored to prevent the population of these states; for that purpose obstructing the laws for naturalization of foreigners; refusing to pass others to encourage their migration hither, and raising the conditions of new appropriations of lands. He has obstructed the administration of justice, by refusing his assent to laws for establishing judiciary powers. He has made judges dependent on his will alone, for the tenure of their offices, and the amount and payment of their salaries. He has erected a multitude of new offices, and sent hither swarms of officers to harass our people, and eat out their substance. He has kept among us, in times of peace, standing armies without the consent of our legislature. He has affected to render the military independent of and superior to civil power. He has combined with others to subject us to a jurisdiction foreign to our constitution, and unacknowledged by our laws; giving his assent to their acts of pretended legislation: For quartering large bodies of armed troops among us: For protecting them, by mock trial, from punishment for any murders which they should commit on the inhabitants of these states: For cutting off our trade with all parts of the world: For imposing taxes on us without our consent: For depriving us in many cases, of the benefits of trial by jury: For transporting us beyond seas to be tried for pretended offenses: For abolishing the free system of English laws in a neighboring province, establishing therein an arbitrary government, and enlarging its boundaries so as to render it at once an example and fit instrument for introducing the same absolute rule in these colonies: For taking away our charters, abolishing our most valuable laws, and altering fundamentally the forms of our governments: For suspending our own legislatures, and declaring themselves invested with power to legislate for us in all cases whatsoever. He has abdicated government here, by declaring us out of his protection and waging war against us. He has plundered our seas, ravaged our coasts, burned our towns, and destroyed the lives of our people. He is at this time transporting large armies of foreign mercenaries to complete the works of death, desolation and tyranny, already begun with circumstances of cruelty and perfidy scarcely paralleled in the most barbarous ages, and totally unworthy the head of a civilized nation. He has constrained our fellow citizens taken captive on the high seas to bear arms against their country, to become the executioners of their friends and brethren, or to fall themselves by their hands. He has excited domestic insurrections amongst us, and has endeavored to bring on the inhabitants of our frontiers, the merciless Indian savages, whose known rule of warfare, is undistinguished destruction of all ages, sexes and conditions. In Jefferson's draft there is a part on slavery here In every stage of these oppressions we have petitioned for redress in the most humble terms: our repeated petitions have been answered only by repeated injury. A prince, whose character is thus marked by every act which may define a tyrant, is unfit to be the ruler of a free people. Nor have we been wanting in attention to our British brethren. We have warned them from time to time of attempts by their legislature to extend an unwarrantable jurisdiction over us. We have reminded them of the circumstances of our emigration and settlement here. We have appealed to their native justice and magnanimity, and we have conjured them by the ties of our common kindred to disavow these usurpations, which, would inevitably interrupt our connections and correspondence. We must, therefore, acquiesce in the necessity, which denounces our separation, and hold them, as we hold the rest of mankind, enemies in war, in peace friends. We, therefore, the representatives of the United States of America, in General Congress, assembled, appealing to the Supreme Judge of the world for the rectitude of our intentions, do, in the name, and by the authority of the good people of these colonies, solemnly publish and declare, that these united colonies are, and of right ought to be free and independent states; that they are absolved from all allegiance to the British Crown, and that all political connection between them and the state of Great Britain, is and ought to be totally dissolved; and that as free and independent states, they have full power to levy war, conclude peace, contract alliances, establish commerce, and to do all other acts and things which independent states may of right do. And for the support of this declaration, with a firm reliance on the protection of Divine Providence, we mutually pledge to each other our lives, our fortunes and our sacred honor. JOHN HANCOCK, President");
delay(5000);
  }
}
