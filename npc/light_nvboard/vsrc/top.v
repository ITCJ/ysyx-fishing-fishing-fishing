module top (
    input clk,
    input rst,
    input [7:0] sw,
    input ps2_clk,
    input ps2_data,
    output reg [15:0] ledr,
    output VGA_CLK,
    output VGA_HSYNC,
    output VGA_VSYNC,
    output VGA_BLANK_N,
    output [7:0] VGA_R,
    output [7:0] VGA_G,
    output [7:0] VGA_B,
    output [7:0] seg0,
    output [7:0] seg1,
    output [7:0] seg2,
    output [7:0] seg3,
    output [7:0] seg4,
    output [7:0] seg5,
    output [7:0] seg6,
    output [7:0] seg7
);
  
  reg [31:0] count;
  always @(posedge clk) begin
    if (rst) begin ledr <= 1; count <= 0; end
    else begin
      if (count == 0) ledr <= {ledr[14:0], ledr[15]};
      count <= (count >= 5000000 ? 32'b0 : count + 1);
    end
  end

endmodule

// example moduel
// module light(
//   input clk,
//   input rst,
//   output reg [15:0] ledr
// );
//   reg [31:0] count;
//   always @(posedge clk) begin
//     if (rst) begin ledr <= 1; count <= 0; end
//     else begin
//       if (count == 0) ledr <= {ledr[14:0], ledr[15]};
//       count <= (count >= 5000000 ? 32'b0 : count + 1);
//     end
//   end
// endmodule