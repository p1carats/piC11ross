# piC11ross
![CI status](https://github.com/inspwastaken/piC11ross/actions/workflows/ci.yml/badge.svg)

Complete reimplementation of Picross written in C, with solver and level generator.

> **What is Picross?** Also known as Nonograms and various other names, Picross are picture logic puzzles in which cells in a grid must be colored or left blank according to numbers at the side of the grid to reveal a hidden picture. In this puzzle type, the numbers are a form of discrete tomography that measures how many unbroken lines of filled-in squares there are in any given row or column. For example, a clue of "4 8 3" would mean there are sets of four, eight, and three filled squares, in that order, with at least one blank square between successive sets.

## Getting started

Clone this repo.

## Components

### Level generator

This part of the project must support several key features :
 - Generate from a user-choosen image using a py script (soon) and a random-defined pattern
 - Support an unlimited number of column/lines 

### Resolver

This resolver eventually represents the hardest part of this project. This is a critical component whose able to validate and complete any Picross.
This algorithm must support every generated grid, and resloves it in a human-comprehensive way (i.e. without cheating).

## Testing

Unit tests are powered by a custom library based on [MinUnit](http://www.jera.com/techinfo/jtns/jtn002.html).

For compatibility reasons, unit tests are **only available on Linux** for now.

## Licensing

Licensed under [MIT](LICENSE).

```
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```