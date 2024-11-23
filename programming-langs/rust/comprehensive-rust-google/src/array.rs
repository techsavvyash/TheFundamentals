
fn transpose(matrix: [[i32; 3]; 3]) -> [[i32; 3]; 3] {
  let mut transposed_matrix: [[i32; 3]; 3] = matrix;
    for row in 0..3 {
      for col in 0..3 {
        transposed_matrix[row][col] = matrix[col][row];
        transposed_matrix[col][row] = matrix[row][col];
      }
    }
    
    return transposed_matrix;
}

#[test]
fn test_transpose() {
    let matrix = [
        [101, 102, 103], //
        [201, 202, 203],
        [301, 302, 303],
    ];
    let transposed = transpose(matrix);
    assert_eq!(
        transposed,
        [
            [101, 201, 301], //
            [102, 202, 302],
            [103, 203, 303],
        ]
    );
}

fn main() {
    // arrays
    let mut a: [i8; 10] = [42; 10]; // this is defining an array in the same way
    a[5] = 0;
    println!("a: {a:#?}"); // pretty print
    println!("a: {a:?}"); // normal stdout

    // lets iterate over it
    for item in a {
      println!("item {}",item);
    }

    // let's move over to nested arrays
    let array = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];
    println!("nested element access: {}", array[0][2]);

    // testing transpose
    let matrix = [
        [101, 102, 103], // <-- the comment makes rustfmt add a newline
        [201, 202, 203],
        [301, 302, 303],
    ];

    println!("matrix: {:#?}", matrix);
    let transposed = transpose(matrix);
    println!("transposed: {:#?}", transposed);
}
