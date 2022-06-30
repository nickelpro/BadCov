module BadCov (
    input  clk,
    input  select,
    input  a,
    input  b,
    output c
);
  reg latch;
  // verilog_format: off
  always_ff @(posedge clk) begin
    if(select)
      latch <= a & b;
    else
      latch <= a | b;
  end
  // verilog_format: on

  assign c = latch;

endmodule
