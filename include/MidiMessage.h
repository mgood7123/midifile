//
// Programmer:    Craig Stuart Sapp <craig@ccrma.stanford.edu>
// Creation Date: Sat Feb 14 20:36:32 PST 2015
// Last Modified: Sun Feb 15 20:32:19 PST 2015
// Filename:      midifile/include/MidiMessage.h
// Website:       http://midifile.sapp.org
// Syntax:        C++11
// vim:           ts=3 expandtab
//
// Description:   Storage for bytes of a MIDI message for use in MidiFile
//                class.
//

#ifndef _MIDIMESSAGE_H_INCLUDED
#define _MIDIMESSAGE_H_INCLUDED

#include <vector>

using namespace std;

typedef unsigned char  uchar;
typedef unsigned short ushort;
typedef unsigned long  ulong;

class MidiMessage : public vector<uchar> {
	public:
		               MidiMessage          (void);
		               MidiMessage          (int command);
		               MidiMessage          (int command, int p1);
		               MidiMessage          (int command, int p1, int p2);
                     MidiMessage          (MidiMessage& message);
                     MidiMessage          (vector<uchar>& message);
                     MidiMessage          (vector<char>& message);
                     MidiMessage          (vector<int>& message);

                    ~MidiMessage         ();

      MidiMessage&   operator=            (MidiMessage& message);
      MidiMessage&   operator=            (vector<uchar>& bytes);
      MidiMessage&   operator=            (vector<char>& bytes);
      MidiMessage&   operator=            (vector<int>& bytes);
      void           setSize              (int asize);
      int            getSize              (void);
      int            setSizeToCommand     (void);
      int            resizeToCommand      (void);

      int            getTempoMicro        (void);
      int            getTempoMicroseconds (void);
      double         getTempoSeconds      (void);
      double         getTempoBPM          (void);
      double         getTempoTPS          (int tpq);
      double         getTempoSPT          (int tpq);

      int            isMetaMessage        (void);
      int            isNoteOff            (void);
      int            isNoteOn             (void);
      int            isAftertouch         (void);
      int            isController         (void);
      int            isTimbre             (void);
      int            isPatchChange        (void);
      int            isPressure           (void);
      int            isPitchbend          (void);

      int            isMeta               (void);
      int            isTempo              (void);

      int            getCommandNibble     (void);
      int            getCommandByte       (void);
      int            getChannelNibble     (void);
      int            getChannel           (void);

      void           setCommandByte       (int value);
      void           setCommand           (int value);
      void           setCommand           (int value, int p1);
      void           setCommand           (int value, int p1, int p2);
      void           setCommandNibble     (int value);
      void           setChannelNibble     (int value);
      void           setChannel           (int value);
      void           setParameters        (int p1, int p2);
      void           setParameters        (int p1);
      void           setMessage           (vector<uchar>& message);
      void           setMessage           (vector<char>& message);
      void           setMessage           (vector<int>& message);

      void           setTempo             (double tempo);
      void           setMetaTempo         (double tempo);

};


#endif /* _MIDIMESSAGE_H_INCLUDED */


