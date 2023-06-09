// https://www.machiningdoctor.com/charts/metric-thread-charts/
// https://www.machiningdoctor.com/charts/unified-inch-threads-charts/
void Thread() {
  double stepsPerSec;
  if (Thread_Mode == 0) {            //----Inch Threading----//
    TPI = TPI_Array[TPI_Array_Pos];
    rpm = ((LeadScrew_TPI*(SpindleRPM))/(TPI * TPI));        // This outputs Leadscrew RPM
  } 
  else if (Thread_Mode == 1) {    //----Metric Threading----//
    Pitch = Pitch_Array[Pitch_Array_Pos];
    rpm = .00155*SpindleRPM*LeadScrew_TPI*(Pitch*Pitch);
  }
  stepsPerSec = ((rpm/60)*LeadSPR);     
  LeadScrew.setSpeed(stepsPerSec);
}

void Auto_Thread() {
  // use "Encoder_Angle" to save the spindle angle when starting the thread, and then use the saved value to start the thread
  // may have to parse info to and from "Spindle_Angle()"
  // add a thread root? calculate proper dims based off of thread?
  // due to the 2 steppers going on the crossslide and lead screw axis, in threading this could cause the cutter to cut on both sides
    // -to fix this calculate the extra lead that the lead screw should start, and start it early so the cut stays on the leading edge of the tool

  /* Variables that are already declared: 
      in_DOC / mm_DOC - depth of cutting pass - user input
      in_Outside_Diameter / mm_Outside_Diameter - Outer Diameter of thread - user input
      in_length_of_cut / mm_length_of_cut - Length of thread - user input
      in_Thread_Depth / mm_Thread_Depth - total depth of thread - calculated
  */

  Spindle_Angle();                      // will need to be continuously polled inorder to start at the same angle with each restart

  //----Calculate Thread Depth----//      // NEED TO DO: convert these to step length, rebuild only when changed
  if (Thread_Mode == 0 && SpindleRPM == 0) {in_Minor_Diameter();}  // dont want to do unneccessary calcs while the spindle is turning
  if (Thread_Mode == 1 && SpindleRPM == 0) {mm_Minor_Diameter();}  // dont want to do unneccessary calcs while the spindle is turning

  //start feed if Current Encoder angle == original encoder angle

}

void mm_Minor_Diameter() {
  // only ran when called for in menu, not while lathe is running
  // May have to add a fit class calculation
  Pitch = Pitch_Array[Pitch_Array_Pos];
  float Height = .866025404 * Pitch;
  mm_Thread_Depth = .625 * Height;
}

void in_Minor_Diameter() {
  // only ran when called for in menu, not while lathe is running
  // May have to add a fit class calculation
  TPI = TPI_Array[TPI_Array_Pos];
  float in_Pitch = 1/TPI;
  float Height = .866025404 * in_Pitch;
  in_Thread_Depth = .625 * Height;
} 