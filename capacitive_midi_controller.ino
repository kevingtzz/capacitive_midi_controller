// First parameter is the event type (0x09 = note on, 0x08 = note off).
// Second parameter is note-on/note-off, combined with the channel.
// Channel can be anything between 0-15. Typically reported to the user as 1-16.
// Third parameter is the note number (48 = middle C).
// Fourth parameter is the velocity (64 = normal, 127 = fastest).

#include <CapacitiveSensor.h>

byte signal_led = 16;

CapacitiveSensor key_c = CapacitiveSensor(2,3);//( control out, sensor in)
bool c_is_typed = false;

CapacitiveSensor key_d = CapacitiveSensor(2,4);
bool d_is_typed = false;

CapacitiveSensor key_e = CapacitiveSensor(2,5);
bool e_is_typed = false;

CapacitiveSensor key_f = CapacitiveSensor(2,6);
bool f_is_typed = false;

CapacitiveSensor key_g = CapacitiveSensor(2,7);
bool g_is_typed = false;

CapacitiveSensor key_a = CapacitiveSensor(2,8);
bool a_is_typed = false;

CapacitiveSensor key_b = CapacitiveSensor(2,9);
bool b_is_typed = false;

unsigned int tolerance = 150;

void noteOn(byte channel, byte pitch, byte velocity) {
  MIDIEvent noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MIDIUSB.write(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  MIDIEvent noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MIDIUSB.write(noteOff);
}

// First parameter is the event type (0x0B = control change).
// Second parameter is the event type, combined with the channel.
// Third parameter is the control number number (0-119).
// Fourth parameter is the control value (0-127).

void controlChange(byte channel, byte control, byte value) {
  MIDIEvent event = {0x0B, 0xB0 | channel, control, value};
  MIDIUSB.write(event);
}

void setup() {
  Serial.begin(115200);
  pinMode(signal_led, OUTPUT);
  key_c.set_CS_AutocaL_Millis(0xFFFFFFF);
  key_d.set_CS_AutocaL_Millis(0xFFFFFFF);
}

void loop() {
  
  unsigned long value_key_c = key_c.capacitiveSensor(30);
  if (value_key_c > tolerance) {
    if (!c_is_typed) {
      digitalWrite(signal_led, HIGH);
      noteOn(0, 48, 64);   // Channel 0, middle C, normal velocity
      MIDIUSB.flush();
      c_is_typed = true;      
    }
  } else {
    if (c_is_typed) {
      digitalWrite(signal_led, LOW);
      noteOff(0, 48, 64);  // Channel 0, middle C, normal velocity
      MIDIUSB.flush();
      c_is_typed = false;    
    }
  }
  
  unsigned long value_key_d = key_d.capacitiveSensor(30);
  if (value_key_d > tolerance) {
    if (!d_is_typed) {
      digitalWrite(signal_led, HIGH);
      noteOn(0, 50, 64);   // Channel 0, middle C, normal velocity
      MIDIUSB.flush();
      d_is_typed = true;      
    }
  } else {
    if (d_is_typed) {
      digitalWrite(signal_led, LOW);
      noteOff(0, 50, 64);  // Channel 0, middle C, normal velocity
      MIDIUSB.flush();
      d_is_typed = false;    
    }
  }

  unsigned long value_key_e = key_e.capacitiveSensor(30);
  if (value_key_e > tolerance) {
    if (!e_is_typed) {
      digitalWrite(signal_led, HIGH);
      noteOn(0, 50, 64);   // Channel 0, middle C, normal velocity
      MIDIUSB.flush();
      e_is_typed = true;      
    }
  } else {
    if (e_is_typed) {
      digitalWrite(signal_led, LOW);
      noteOff(0, 50, 64);  // Channel 0, middle C, normal velocity
      MIDIUSB.flush();
      e_is_typed = false;    
    }
  }

  unsigned long value_key_f = key_f.capacitiveSensor(30);
  if (value_key_f > tolerance) {
    if (!f_is_typed) {
      digitalWrite(signal_led, HIGH);
      noteOn(0, 50, 64);   // Channel 0, middle C, normal velocity
      MIDIUSB.flush();
      f_is_typed = true;      
    }
  } else {
    if (f_is_typed) {
      digitalWrite(signal_led, LOW);
      noteOff(0, 50, 64);  // Channel 0, middle C, normal velocity
      MIDIUSB.flush();
      f_is_typed = false;    
    }
  }

  unsigned long value_key_g = key_g.capacitiveSensor(30);
  if (value_key_g > tolerance) {
    if (!g_is_typed) {
      digitalWrite(signal_led, HIGH);
      noteOn(0, 50, 64);   // Channel 0, middle C, normal velocity
      MIDIUSB.flush();
      g_is_typed = true;      
    }
  } else {
    if (g_is_typed) {
      digitalWrite(signal_led, LOW);
      noteOff(0, 50, 64);  // Channel 0, middle C, normal velocity
      MIDIUSB.flush();
      g_is_typed = false;    
    }
  }

  unsigned long value_key_a = key_a.capacitiveSensor(30);
  if (value_key_a > tolerance) {
    if (!a_is_typed) {
      digitalWrite(signal_led, HIGH);
      noteOn(0, 50, 64);   // Channel 0, middle C, normal velocity
      MIDIUSB.flush();
      a_is_typed = true;      
    }
  } else {
    if (a_is_typed) {
      digitalWrite(signal_led, LOW);
      noteOff(0, 50, 64);  // Channel 0, middle C, normal velocity
      MIDIUSB.flush();
      a_is_typed = false;    
    }
  }

  unsigned long value_key_b = key_b.capacitiveSensor(30);
  if (value_key_b > tolerance) {
    if (!b_is_typed) {
      digitalWrite(signal_led, HIGH);
      noteOn(0, 50, 64);   // Channel 0, middle C, normal velocity
      MIDIUSB.flush();
      b_is_typed = true;      
    }
  } else {
    if (b_is_typed) {
      digitalWrite(signal_led, LOW);
      noteOff(0, 50, 64);  // Channel 0, middle C, normal velocity
      MIDIUSB.flush();
      b_is_typed = false;    
    }
  }
//Serial.println(value_key_c);
  
  // controlChange(0, 10, 65); // Set the value of controller 10 on channel 0 to 65
}
