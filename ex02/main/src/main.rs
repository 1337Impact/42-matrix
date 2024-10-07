

// lerp = a + (b - a) * t
fn lerp(u: f32, v: f32, t: f32) -> f32{
    return t.mul_add(v - u, u);
}

fn lerp(u: Vec<i32>, v: Vec<i32>, t: f32) -> Vec<i32> {
    let mut numbers: Vec<i32> = Vec::new();
    for e in &u {

    }
}


fn main() {
    // let x: f32 = 5.0;
    let a: f32 = 0.0;
    let b: f32 = 1938.0;

    let numbers: Vec<i32> = vec![1, 2, 3, 4, 5];
    println!("vector: {:?}", numbers);

    for e in numbers {
        println!("n {}", e);
    }


    println!("Integer: {}", lerp(a, b, 1.0));
    let matrix: [[i32; 3]; 3] = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9],
    ];

    // Print the matrix
    for row in &matrix {
        println!("{:?}", row);
    }
}
