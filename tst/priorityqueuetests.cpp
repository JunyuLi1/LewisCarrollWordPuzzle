#include <PriorityQueue.hpp>
#include <catch2/catch_amalgamated.hpp>

namespace {
namespace proj5 = shindler::ics46::project5;
// NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers,
// readability-magic-numbers)

// As always, this is a STARTING POINT of TEST_CASE( cases
// and is not an exhaustive set of TEST_CASE( cases.
// You should be sure to TEST_CASE( EVERY function of
// your priority queue as well as the Lewis Carroll puzzle.
TEST_CASE("PriorityQueue:CreateWithInsert3:ExpectFront3",
          "[Required][PriorityQueue]") {
    proj5::PriorityQueue<int> pqueue;
    pqueue.push(3);
    REQUIRE(pqueue.min() == 3);
}

TEST_CASE("PriorityQueue:CreateWithInsert3,5:ExpectFront3",
          "[Required][PriorityQueue]") {
    proj5::PriorityQueue<int> pqueue;
    pqueue.push(3);
    pqueue.push(5);
    REQUIRE(pqueue.min() == 3);
}

TEST_CASE("PriorityQueue:CreateWithInsert3,2:ExpectFront2",
          "[Required][PriorityQueue]") {
    proj5::PriorityQueue<int> pqueue;
    pqueue.push(3);
    pqueue.push(2);
    REQUIRE(pqueue.min() == 2);
}
// NOLINTEND

TEST_CASE("simpleminheap",
          "[Required][PriorityQueue]") {
    proj5::PriorityQueue<int> pqueue;
    pqueue.push(16);
    pqueue.push(18);
    pqueue.push(34);
    pqueue.push(62);
    pqueue.push(21);
    pqueue.push(4);
    REQUIRE(pqueue.min() == 4);
    REQUIRE(pqueue.size()==6);
    pqueue.popMin();
    REQUIRE(pqueue.min()==16);
}

}  // namespace
