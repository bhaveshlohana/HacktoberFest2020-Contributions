module helloWorld();

initial
  begin
    $display("Hello World!"); // display message
    $finish; // needed for simulation to end
  end

endmodule